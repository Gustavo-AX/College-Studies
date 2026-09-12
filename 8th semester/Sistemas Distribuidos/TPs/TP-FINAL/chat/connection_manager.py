"""
Cada usuário conectado ao chat mantém um WebSocket.
Esta classe mantém um dicionário que mapeia usernames e websocket.
Assim, o servidor sabe para qual usuário enviar mensagem.
"""
from fastapi import WebSocket
from typing import Dict

class ConnectionManager:
    def __init__(self):
        # Mapeia username e WebSocket
        self.active_connections: Dict[str, dict] = {}
    
    # Aceita a conexão WebSocket e registra no dicionário interno.
    async def connect(self, username: str, websocket: WebSocket):
        await websocket.accept()
        self.active_connections[username] = {
            "ws": websocket,
            "talking_to": None
        }

    # Remove o WebSocket associado ao username quando o cliente desconecta.
    def disconnect(self, username: str):
        if username in self.active_connections:
            del self.active_connections[username]

    # Envia um JSON para um usuário específico (se estiver conectado).
    async def send_personal_message(self, message: dict, username: str):
        conn = self.active_connections.get(username)
        if conn:
            await conn["ws"].send_json(message)

    # Verifica se um usuário está conectado ao WebSocket.
    def is_connected(self, username: str) -> bool:
        return username in self.active_connections

    # Define com quem o usuário atual está conversando
    def set_talking_to(self, username: str, target: str):
        if username in self.active_connections:
            self.active_connections[username]["talking_to"] = target

    def get_talking_to(self, username: str) -> str:
        conn = self.active_connections.get(username)
        if conn:
            return conn["talking_to"]
        return None