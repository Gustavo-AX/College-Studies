"""
Este módulo é responsável por permitir que o Serviço de Chat valide tokens
consultando diretamente o serviço de Autenticação.

Ele envia o token para o authentication e recebe o username correspondente se o token for válido.
"""

import httpx
import os
from dotenv import load_dotenv
from fastapi import HTTPException

load_dotenv()

AUTH_URL = os.getenv("AUTH_URL")

# Classe para comunicação com o AuthService.
class AuthClient:

    # Envia o token para o AuthService e retorna o username se for válido.
    @staticmethod
    async def verify_token(token: str) -> str:
        # Monta o header: Bearer <token>
        headers = {"Authorization": f"Bearer {token}"}
        
        # Endpoint público para validar tokens
        url = f"{AUTH_URL}/verify-token"
 
        # Usa chamadas assíncronas
        async with httpx.AsyncClient() as client:
            try:
                response = await client.get(url, headers=headers)
            except Exception:
                raise HTTPException(status_code=500, detail="Erro ao contactar o AuthService.")

        if response.status_code != 200:
            raise HTTPException(status_code=401, detail="Token inválido.")

        data = response.json()

        # Esperamos {"user": "username"}
        return data.get("user")
