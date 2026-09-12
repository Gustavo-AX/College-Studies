"""
Este módulo contém a lógica de negócios do Chat:

salvar mensagens no banco de dados
recuperar histórico entre dois usuários
"""

from sqlalchemy.orm import Session
from models import Message

class ChatService:
    def __init__(self, db: Session):
        self.db = db

    # Recebe uma sessão de banco de dados na criação.
    def save_message(self, sender: str, receiver: str, content: str):
        msg = Message(
            sender=sender,
            receiver=receiver,
            content=content
        )

        self.db.add(msg)
        self.db.commit()
        self.db.refresh(msg)

        return msg

    # Busca histórico de mensagens trocadas entre dois users
    def get_history(self, user1: str, user2: str):
        return (
            self.db.query(Message)
            .filter(
                ((Message.sender == user1) & (Message.receiver == user2)) |
                ((Message.sender == user2) & (Message.receiver == user1))
            )
            .order_by(Message.timestamp)
            .all()
        )
