"""
Define os modelos Pydantic usados para validação dos dados que o cliente envia.
Isso impede dados inválidos antes mesmo de chegar na lógica da API.
"""

from pydantic import BaseModel

# Define quais dados o cliente deve enviar ao registrar.
class UserCreate(BaseModel):
    username: str 
    password: str

# Define quais dados necessários para login
class UserLogin(BaseModel):
    username: str
    password: str
