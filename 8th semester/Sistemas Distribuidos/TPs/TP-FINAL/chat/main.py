from fastapi import FastAPI, WebSocket, WebSocketDisconnect, Depends, HTTPException
from fastapi.middleware.cors import CORSMiddleware
from fastapi import Header

from sqlalchemy.orm import Session
from database import Base, engine, SessionLocal
from connection_manager import ConnectionManager
from auth_client import AuthClient
from chat_service import ChatService
from schemas import MessageCreate, MessageRead
import json

import asyncio
import websockets
import os

# Cria tabelas
Base.metadata.create_all(bind=engine)

app = FastAPI()

# Conectar com o canal global
CHANNEL_URL = os.getenv("CHANNEL_URL") 
channel_ws = None

@app.on_event("startup")
async def startup():
    global channel_ws
    channel_ws = await websockets.connect(CHANNEL_URL)
    asyncio.create_task(listen_channel())

# CORS 
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# Gerenciador de conexões
manager = ConnectionManager()

# Sessão do db
def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()

# WEBSOCKET
@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    # 1) Aceita token via query string
    token = websocket.query_params.get("token")

    if not token:
        await websocket.close()
        return

    # 2) Valida token no AuthService
    try:
        username = await AuthClient.verify_token(token)
    except HTTPException:
        await websocket.close()
        return

    # 3) Registra a conexão
    await manager.connect(username, websocket)

    try:
        # Loop principal do WebSocket
        while True:
            data = await websocket.receive_text()
            # Dados recebidos como JSON
            json_data = json.loads(data)

            if json_data.get("type") == "join":
                manager.set_talking_to(username, json_data["talking_to"])
                continue

            # Valida estrutura da mensagem
            msg_in = MessageCreate(**json_data)

            # 4) Salva mensagem
            # Abrimos DB session manualmente (WS não aceita Depends)
            db = SessionLocal()
            chat = ChatService(db)
            saved = chat.save_message(
                sender=username,
                receiver=msg_in.receiver,
                content=msg_in.content
            )
            db.close()

            # 5) Envia para o receiver se estiver conectado, se não, manda para o canal

            if manager.is_connected(msg_in.receiver):
                if manager.get_talking_to(msg_in.receiver) != username:
                    continue 
                await manager.send_personal_message(
                    {
                        "id": saved.id,
                        "sender": username,
                        "receiver": msg_in.receiver,
                        "content": msg_in.content,
                        "timestamp": str(saved.timestamp)
                    },
                    msg_in.receiver
                )
            else:
                await channel_ws.send(json.dumps({
                    "id": saved.id,
                    "sender": username,
                    "receiver": msg_in.receiver,
                    "content": msg_in.content,
                    "timestamp": str(saved.timestamp)
                }))

    except WebSocketDisconnect:
        manager.disconnect(username)


# HISTÓRICO DE MENSAGENS
# Retorna histórico entre usuário autenticado e 'other_user'.
# O token vem no header: Authorization: Bearer <token>
@app.get("/history/{other_user}", response_model=list[MessageRead])
async def history(
    other_user: str,
    db: Session = Depends(get_db),
    authorization: str = Header(None)
):

    if not authorization:
        raise HTTPException(401, "Token ausente")

    # Extrai o token
    if not authorization.startswith("Bearer "):
        raise HTTPException(401, "Header Authorization inválido")

    token = authorization.split(" ")[1]

    # Valida token no AuthService
    current_user = await AuthClient.verify_token(token)

    # Busca histórico
    chat = ChatService(db)
    msgs = chat.get_history(current_user, other_user)
    return msgs

async def listen_channel():
    global channel_ws
    while True:
        raw = await channel_ws.recv()
        data = json.loads(raw)

        sender = data["sender"]
        receiver = data["receiver"]

        if manager.get_talking_to(receiver) != sender:
            continue

        if manager.is_connected(receiver):
            await manager.send_personal_message(data, receiver)

# Responde ping do balanceador
@app.get("/health")
def health():
    return {"status": "ok"}