# Trabalho Prático 01 - Sistemas distribuídos

### Dupla: Gustavo Assis e Thiago Ribeiro

## Parte 01

### Gerador e Verificador de Primos com Pipes em C
Um exemplo prático de comunicação entre processos (IPC) em C, demonstrando o padrão produtor-consumidor com as chamadas de sistema fork() e pipe().

### Visão Geral
Este programa ilustra como dois processos podem colaborar para realizar uma tarefa. Um processo pai (produtor) gera uma sequência de números inteiros aleatórios e os envia para um processo filho (consumidor). O filho, por sua vez, recebe esses números, verifica se são primos e exibe o resultado no terminal.

A comunicação entre eles é feita através de um pipe, um canal unidirecional que conecta a saída do processo pai à entrada do processo filho.

### Funcionamento Detalhado
O fluxo de execução é dividido da seguinte forma:

#### 1. Processo Pai (Produtor)
Cria um pipe e, em seguida, um processo filho usando fork().

Fecha a sua ponta de leitura do pipe, pois ele apenas escreverá dados.

Inicia um loop para gerar 100 números aleatórios.

Converte cada número para uma string e o envia através do pipe para o filho.

Ao final do loop, envia o valor 0 como um sinal para o filho de que a transmissão terminou.

Aguarda a finalização do processo filho com wait() para evitar processos órfãos.

#### 2. Processo Filho (Consumidor)
Fecha a sua ponta de escrita do pipe, pois ele apenas lerá os dados.

Entra em um loop para ler os dados enviados pelo pai.

Converte a string recebida de volta para um número inteiro.

Verifica se o número é 0. Se for, encerra o loop.

Utiliza a função isprime() para testar a primalidade do número.

Imprime o número e o resultado da verificação na tela.

### Tecnologias e Conceitos Chave
fork(): Cria um novo processo que é uma cópia exata do processo atual. É a base para a criação de novos processos em sistemas Unix-like.

pipe(): Estabelece um canal de comunicação simples e unidirecional entre processos relacionados (como pai e filho).

write() / read(): Funções de baixo nível para enviar e receber bytes através de descritores de arquivo, como os de um pipe.

wait(): Permite que um processo pai espere pelo término de um de seus processos filhos.

### Como Compilar e Executar
Este código foi projetado para ser executado em um sistema operacional baseado em Unix (como Linux ou macOS).

Salve o código-fonte em um arquivo, por exemplo, primos.c.

Abra o terminal e compile o programa usando o GCC:
```
g++ Parte1.cpp
```
Execute o programa compilado:
```
./a.out
```
A saída será uma lista de 100 números, cada um seguido pela sua classificação como "é primo" ou "não é primo".

## Parte 02

### Produtor-Consumidor com Pthreads e Semáforos em C++
Este projeto implementa a solução clássica para o problema do Produtor-Consumidor usando threads POSIX (pthread) e semáforos para sincronização.

### Visão Geral
O programa cria múltiplas threads produtoras e consumidoras que operam sobre um buffer circular compartilhado de tamanho fixo.

Produtores: Geram números inteiros aleatórios e os inserem no buffer.

Consumidores: Retiram números do buffer e verificam se são primos.

O objetivo é processar um grande volume de itens (M) de forma concorrente, medindo o tempo total de execução.

### Mecanismos de Sincronização
A coordenação entre as threads é feita com três semáforos:

```mutex:``` Garante o acesso exclusivo ao buffer, prevenindo condições de corrida.

```posicoes_vazias:``` Bloqueia os produtores quando o buffer está cheio.

```posicoes_ocupadas:``` Bloqueia os consumidores quando o buffer está vazio.

O programa também registra a ocupação do buffer ao longo do tempo e salva os dados no arquivo ocupacao.txt.

### Como Compilar e Executar
Este código deve ser compilado em um ambiente Unix-like (Linux, macOS) que suporte pthreads.

Salve o código em um arquivo, por exemplo, produtor_consumidor.cpp.

Compile no terminal usando g++, incluindo a flag -lpthread para linkar a biblioteca de threads:
```
g++ Parte2.cpp
```
Execute o programa:
```
./a.out
```
Ao final da execução, o programa exibirá o tempo total e confirmará a criação do arquivo ocupacao.txt.
