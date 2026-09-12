"""
Este arquivo gerencia toda a configuração do banco de dados usando SQLAlchemy.

Lê a URL do banco pelo arquivo .env
Cria engine (conexão principal com o PostgreSQL)
Cria SessionLocal (cada requisição abre uma sessão própria)
Define a Base para os modelos ORM

Todos os arquivos que trabalham com o banco importam componentes daqui
"""

from sqlalchemy import create_engine
from sqlalchemy.orm import declarative_base
from sqlalchemy.orm import sessionmaker
import os
from dotenv import load_dotenv

# Carrega o conteúdo do arquivo .env
load_dotenv()

# Lê a variável DATABASE_URL do .env, que basicamente é a url do nosso banco de dados
DATABASE_URL = os.getenv("DATABASE_URL")

# Cria o engine, que é a conexão principal com o PostgreSQL (Tudo no SQLAlchemy depende desse engine.)
engine = create_engine(DATABASE_URL)

# Cria o SessionLocal, que é um "gerador de sessões". (A cada requisição, o FastAPI vai criar e fechar uma sessão usando isso.) 
SessionLocal = sessionmaker(
    autocommit=False,   # Não envia alterações automaticamente
    autoflush=False,    # Não atualiza automaticamente o estado
    bind=engine         # Usa o engine
)

# Cria a classe Base, da qual os modelos irão herdar.
Base = declarative_base()
