import socket
import threading
import os
import time
import argparse
import json
import hashlib
import math
import random 

"""
Deixo como referência um vídeo sobre essa aplicação:
https://www.youtube.com/watch?v=HMUDtK82ROE
"""

"""
O arquivo launcher.py serve como um atalho para criar vários peers de uma vez (abre vários terminais com esse código)
"""

"""
Para rodar o código, faça para o primeiro peer:
py peer.py --ip 127.0.0.1 --port 5000 --file teste.txt
Para os demais, faça:
py peer.py --ip 127.0.0.1 --port 5001 --neighbors 127.0.0.1:5000 --arquivo_desejado teste.txt
py peer.py --ip 127.0.0.1 --port 5002 --neighbors 127.0.0.1:5000,127.0.0.1:5001 --arquivo_desejado teste.txt
py peer.py --ip 127.0.0.1 --port 5003 --neighbors 127.0.0.1:5000,127.0.0.1:5001,127.0.0.1:5002 --arquivo_desejado teste.txt
"""

BLOCK_SIZE = 4096  # tamanho do bloco
PEER_PORT = None

#============FUNÇÕES PARA MEXER NO ARQUIVO:=============
def fragmentar_arquivo(nome_arquivo):
    blocos = []
    with open(nome_arquivo, "rb") as f:
        while True:
            dado = f.read(BLOCK_SIZE)
            if not dado:
                break
            blocos.append(dado)
    return blocos


def montar_arquivo(blocos):
    with open(f"ArquivoBaixadoPeloPort_{PEER_PORT}", "wb") as f:
        for b in blocos:
            f.write(b)
    log(f"[Peer] Arquivo final salvo como ArquivoBaixadoPeloPort_{PEER_PORT}")


def checksum(nome_arquivo):
    h = hashlib.sha256()
    with open(nome_arquivo, "rb") as f:
        for chunk in iter(lambda: f.read(4096), b""):
            h.update(chunk)
    return h.hexdigest()

# Registro de troca de mensagens e estados:
def log(msg):
    timestamp = time.strftime("%H:%M:%S")
    linha = f"[{timestamp}] {msg}"
    print(linha)

    # usa a porta global para nomear o arquivo de log
    nome_arquivo = f"peer_{PEER_PORT}.log" if PEER_PORT else "peer.log"

    with open(nome_arquivo, "a") as f:
        f.write(linha + "\n")

# =============FUNÇÕES PARA ESCREVER/LER METADADOS==============
def gerar_metadado(nome_arquivo, block_size):
    tamanho = os.path.getsize(nome_arquivo)
    num_blocos = math.ceil(tamanho / block_size)

    # Calcula o hash:
    h = hashlib.sha256()
    with open(nome_arquivo, "rb") as f:
        for chunk in iter(lambda: f.read(4096), b""):
            h.update(chunk)

    meta = {
        "arquivo": nome_arquivo,
        "tamanho": tamanho,
        "block_size": block_size,
        "num_blocos": num_blocos,
        "hash": h.hexdigest()
    }

    meta_nome = f"{nome_arquivo}.meta"  
    with open(meta_nome, "w") as f:
        json.dump(meta, f, indent=4)

    log(f"[Seeder] Metadado gerado: {meta_nome}")
    return meta


def ler_metadado(meta_nome):
    with open(meta_nome) as f:
        meta = json.load(f)
    log(f"[Leecher] Metadado carregado de {meta_nome}")
    return meta

# =============SERVIDOR (primeiro peer):===========
def servidor(peer_ip, peer_port, blocos, lock):

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((peer_ip, peer_port))
    s.listen()

    log(f"[Servidor] Ouvindo em {peer_ip}:{peer_port}")

    while True:
        try:
            # aceita o endereço
            conn, addr = s.accept()
            # recebe os dados e decofica (para string)
            dados = conn.recv(1024).decode()
            # fecha se não receber
            if not dados:
                conn.close()
                continue
            
            # Tentamos ler a string como um JSON, o que era para ser
            # se não, fecha a conexão
            try:
                pedido = json.loads(dados)
                bloco_id = pedido.get("bloco", -1)
            except json.JSONDecodeError:
                conn.close()
                continue

        # Aqui iremos entrar na região crítica. Uma thread não pode enviar um dado que está sendo escrito
        # isso faria com que um dado incompleto fosse envi          
            # with lock: adquire o lock para o bloco
            with lock:
                # Se o id está no intervalo válido && se ele já está disponível:
                if 0 <= bloco_id < len(blocos) and blocos[bloco_id] is not None:
                    conn.sendall(blocos[bloco_id])
                    log(f"[Servidor] Enviou bloco {bloco_id} para {addr}")
                else:
                    # Se não disponível, envia (b"") indicando ausência do bloco.
                    conn.sendall(b"")  # bloco não disponível
                    log(f"[Servidor] Pedido de bloco {bloco_id} indisponível de {addr}")

            conn.close()

        except Exception as e:
            log(f"[Servidor] Erro: {e}")
            continue


# --------------------- Cliente (baixa blocos) ---------------------

def cliente(vizinhos, blocos, lock):
    num_blocos = len(blocos)       
    # verifica se já tem todos os blocos
    tem_bloco = [b is not None for b in blocos]  
    # caso não tenha
    while not all(tem_bloco):        
        # procura o bloco faltante:
        for i in range(num_blocos):
            if not tem_bloco[i]:
                # percorre os vizinhos em ordem aleatória
                for vizinho_ip, vizinho_port in random.sample(vizinhos, len(vizinhos)):
                    try:
                        # cria socket TCP
                        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                        s.settimeout(2)
                        # conecta
                        s.connect((vizinho_ip, vizinho_port))
                        # prepara a mensagem JSON solicitando o bloco i e envia requisição
                        msg = json.dumps({"bloco": i}).encode()             
                        s.sendall(msg)
                         # buffer para montar os bytes recebidos
                        dados = b""                                       
                        while True:
                            parte = s.recv(BLOCK_SIZE)    # recebe até BLOCK_SIZE bytes por vez
                            # se não tem nada sai
                            if not parte:
                                break
                            dados += parte
                        s.close()

                        if dados:
                            with lock: # região crítica: atualiza a estrutura compartilhada
                                blocos[i] = dados
                                tem_bloco[i] = True
                            log(f"[Cliente] Recebeu bloco {i} de {vizinho_ip}:{vizinho_port}")
                            break   # sai do loop de vizinhos para passar ao próximo bloco faltante
                    except Exception:
                        continue
        time.sleep(1) 


def main():
    
    global BLOCK_SIZE
    global PEER_PORT

    parser = argparse.ArgumentParser(description="Peer-to-Peer File Transfer (Trabalho SD_TP_2)")
    parser.add_argument("--ip", default="127.0.0.1")
    parser.add_argument("--port", type=int, required=True)
    parser.add_argument("--neighbors", default="", help="Lista de vizinhos ip:port separada por vírgula")
    parser.add_argument("--file", help="Arquivo original (se for Seeder)")
    parser.add_argument("--num_blocks", type=int, default=None, help="Número de blocos (usado se .meta não existir)")
    parser.add_argument("--arquivo_desejado", default="arquivo_final.bin", help="Nome do arquivo reconstruído")
    parser.add_argument("--block_size", type=int, default=BLOCK_SIZE, help="Tamanho do bloco em bytes")
    args = parser.parse_args()

    BLOCK_SIZE = args.block_size
    PEER_PORT = args.port

    # Configura log inicial
    if os.path.exists("peer.log"):
        os.remove("peer.log")
    log(f"[Inicialização] Peer iniciado em {args.ip}:{args.port}")

    # Processa vizinhos
    vizinhos = []
    if args.neighbors:
        for v in args.neighbors.split(","):
            ip, port = v.split(":")
            vizinhos.append((ip, int(port)))
    log(f"[Config] Vizinhos: {vizinhos}")

    if args.file:
        # Seeder: tem o arquivo completo, logo ele divide e gera o meta dado
        blocos = fragmentar_arquivo(args.file)
        meta = gerar_metadado(args.file, BLOCK_SIZE)
        log(f"[Seeder] Fragmentou '{args.file}' em {meta['num_blocos']} blocos de {BLOCK_SIZE} bytes.")

    else:
        # Leecher: tenta ler o metadado do arquivo a ser baixado
        nome_meta = f"{args.arquivo_desejado}.meta"
        if os.path.exists(nome_meta):
            meta = ler_metadado(nome_meta)
            BLOCK_SIZE = meta["block_size"]
            blocos = [None] * meta["num_blocos"]
            log(f"[Leecher] Esperando {meta['num_blocos']} blocos ({BLOCK_SIZE} bytes cada).")
        else:
            # se não é erro
            blocos = [None] * args.num_blocks
            log(f"[Leecher] Esperando {args.num_blocks} blocos (sem metadado encontrado).")

    # Lock compartilhado entre threads
    lock = threading.Lock()

    # Inicia servidor em thread separada
    t_servidor = threading.Thread(target=servidor, args=(args.ip, args.port, blocos, lock), daemon=True)
    t_servidor.start()

    # Inicia cliente na thread principal
    cliente(vizinhos, blocos, lock)

    if all(b is not None for b in blocos):  # verifica se todos os blocos agora estão presentes
        if not args.file:   # se não foi iniciado como Seeder
            montar_arquivo(blocos) # monta o arquivo final escrevendo blocos na ordem
            log("[Peer] Download completo!")

            final_hash = checksum(args.arquivo_desejado)  # calcula o hash
            log(f"[Checksum] Arquivo final: {final_hash}")

            # Compara com o hash do metadado, se existir
            if 'meta' in locals() and 'hash' in meta:
                if final_hash == meta["hash"]:  # comparaçao
                    log("[Integridade] Arquivo verificado com sucesso (SHA-256 idêntico ao metadado).")
                else:
                    log("[Integridade] ERRO: Hash diferente do metadado!")  # aviso caso a integridade falhe
            else:
                log("[Integridade] Hash do metadado não encontrado, verificação pulada.")  # não há metadado para comparar

            # Agora o Leecher continua servindo os blocos
            log("[Peer] Agora atuando como Seeder. Aguardando solicitações de outros peers...")
            while True:
                time.sleep(10)

        else:  # Seeder original
            log("[Seeder] Todos os blocos disponíveis. Aguardando solicitações de outros peers...")
            while True:
                time.sleep(10) # Seeder também fica em loop infinito esperando requisições
    else:
        log("[Peer] Download incompleto. Alguns blocos faltam.") 



if __name__ == "__main__":
    main()
