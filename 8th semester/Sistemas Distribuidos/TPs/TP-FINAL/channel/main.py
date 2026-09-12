import asyncio
import json
from fastapi import FastAPI, WebSocket

app = FastAPI()

connections = set()

@app.websocket("/channel")
async def channel_socket(ws: WebSocket):
    await ws.accept()
    connections.add(ws)

    try:
        while True:
            raw = await ws.receive_text()
            data = json.loads(raw)

            # retransmite para todas as instâncias
            for conn in connections:
                if conn != ws:  # evita retornar para origem
                    # Se quiser ver as mensagens que são restransmitidas
                    # print(f"[CANAL] Mensagem retransmitida de {data['sender']} para {data['receiver']}")
                    await conn.send_text(raw)

    except:
        connections.remove(ws)
