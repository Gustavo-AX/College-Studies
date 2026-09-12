Para usar o sistema, o primeiro peer, o qual tem o arquivo, tem que ser iniciado.
Para isso é passado o ip desejado, a porta, e o arquivo de upload.

py peer.py --ip 127.0.0.1 --port 5000 --file teste.txt


Depois, pode se criar os peers que irão baixar esse arquivo. Para cada um
se passa o ip da rede, o seu número de port, uma lista de vizinhos e o arquivo
desejado.

py peer.py --ip 127.0.0.1 --port 5001 --neighbors 127.0.0.1:5000 --arquivo_desejado teste.txt
py peer.py --ip 127.0.0.1 --port 5002 --neighbors 127.0.0.1:5000,127.0.0.1:5001 --arquivo_desejado teste.txt
py peer.py --ip 127.0.0.1 --port 5003 --neighbors 127.0.0.1:5000,127.0.0.1:5001,127.0.0.1:5002 --arquivo_desejado teste.txt