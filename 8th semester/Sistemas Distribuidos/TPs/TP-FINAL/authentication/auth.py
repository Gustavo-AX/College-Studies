"""
Este arquivo contém toda a lógica relacionada à segurança do sistema, ou seja:

Criptografia de senhas utilizando bcrypt
Criação de tokens JWT com tempo de expiração
Decodificação de tokens JWT para validação

Este módulo é usado tanto no processo de registro quanto no de login.
"""

from passlib.context import CryptContext # Responsável por gerar e validar hashes bcrypt
from jose import jwt # Permite criar e validar JWTs (JSON Web Tokens) que é um token seguro para troca de informações
from datetime import datetime, timedelta # Isso serve para colocar um limite de tempo nos tokens
import os # Para carregar variáveis de ambiente
from dotenv import load_dotenv # Para carregar variáveis de ambiente

load_dotenv() # Carrega variáveis do arquivo .env

SECRET_KEY = os.getenv("SECRET_KEY") # Pega o SECRET_KEY do arquivo
ALGORITHM = os.getenv("ALGORITHM")
ACCESS_TOKEN_EXPIRE_MINUTES = int(os.getenv("ACCESS_TOKEN_EXPIRE_MINUTES"))

# Define o esquema de criptografia usando bcrypt
pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")

# Recebe uma senha em texto puro e retorna o hash usando bcrypt.
def hash_password(password: str):
    return pwd_context.hash(password)

# Compara uma senha em texto puro com o hash armazenado no banco.
# Retorna True se a senha corresponder ao hash.
def verify_password(password: str, hash_stored: str):
    return pwd_context.verify(password, hash_stored)

# Cria um token JWT contendo o payload informado em 'data'.
# Também adiciona o campo de expiração ('exp').
def create_access_token(data: dict):
    to_encode = data.copy()
    expire = datetime.utcnow() + timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES) # Calcula horário de expiração
    to_encode.update({"exp": expire})
    return jwt.encode(to_encode, SECRET_KEY, algorithm=ALGORITHM) # Gera o token assinado

# Decodifica um token JWT e retorna seu payload.
# Caso o token seja inválido ou expirado, gera exceções tratadas pelo serviço de autenticação.
def decode_token(token: str):
    return jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
