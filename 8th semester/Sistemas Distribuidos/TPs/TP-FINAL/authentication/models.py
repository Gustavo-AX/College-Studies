"""
Define o modelo User, que representa a tabela 'users' no banco de dados.
"""

from sqlalchemy import Column, Integer, String
from database import Base

# Classe que representa uma tabela no banco 
class User(Base):
    # Define o nome real da tabela
    __tablename__ = "users"

    # Coluna id: chave primária, inteira, e indexada.
    id = Column(Integer, primary_key=True, index=True)

    # Coluna username: string, único, indexado e obrigatório
    username = Column(String, unique=True, index=True, nullable=False)

    # Coluna password_hash: guarda a senha criptografada
    password_hash = Column(String, nullable=False)
