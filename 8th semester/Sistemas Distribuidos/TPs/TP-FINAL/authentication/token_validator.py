"""
Centraliza a validação de tokens JWT para rotas protegidas.
As rotas do AuthService e o ChatService dependem deste módulo.
"""

from fastapi import HTTPException, Depends
from fastapi.security import OAuth2PasswordBearer
from jose import jwt, JWTError, ExpiredSignatureError
import os
from dotenv import load_dotenv

load_dotenv()

SECRET_KEY = os.getenv("SECRET_KEY")
ALGORITHM = os.getenv("ALGORITHM")

# Define forma de receber o token: "Authorization: Bearer <token>"
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="/login")

# Confirma assinatura, expiração e o username

def verify_token(token: str = Depends(oauth2_scheme)):
    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
        username: str = payload.get("sub")

        if username is None:
            raise HTTPException(status_code=401, detail="Token inválido.")
        return username

    except ExpiredSignatureError:
        raise HTTPException(status_code=401, detail="Token expirado.")

    except JWTError:
        raise HTTPException(status_code=401, detail="Token inválido.")
