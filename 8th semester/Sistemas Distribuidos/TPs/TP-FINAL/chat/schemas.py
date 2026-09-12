"""Definine os dados quem tem que receber"""
from pydantic import BaseModel
from datetime import datetime

class MessageCreate(BaseModel):
    receiver: str
    content: str

class MessageRead(BaseModel):
    id: int
    sender: str
    receiver: str
    content: str
    timestamp: datetime

    class Config:
        from_attributes = True
