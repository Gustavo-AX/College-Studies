"""
Este arquivo define todas as rotas HTTP do serviço de autenticação:

Registro de usuários
Login com geração de token JWT
Rota protegida que requer token
Listagem de usuários (usada pelo chat)
Rota pública de verificação de token usada pelo chat
"""

from fastapi import FastAPI, Depends, HTTPException
from sqlalchemy.orm import Session

# Importações internas:
from database import Base, engine, SessionLocal
from models import User
from schemas import UserCreate, UserLogin
from auth import hash_password, verify_password, create_access_token
from token_validator import verify_token

# Middleware para permitir requisições do front ou do chat:
from fastapi.middleware.cors import CORSMiddleware

# Cria as tabelas automaticamente se ainda não existirem
Base.metadata.create_all(bind=engine)

app = FastAPI()

# Configurações de CORS (libera tudo, ideal para desenvolvimento)
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],    # Permite requisições de qualquer origem (requisições dão erro sem isso)
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# Cria uma sessão para acesso ao banco antes da requisição. Fecha a sessão após a resposta.
def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()


# Rota simples para ver se funciona
@app.get("/")
def home():
    return {"msg": "Auth service funcionando!"}


# Registro de usuário:
@app.post("/register")
def register(user: UserCreate, db: Session = Depends(get_db)):

    # Verifica se o user já existe:
    user_db = db.query(User).filter(User.username == user.username).first()
    if user_db:
        raise HTTPException(status_code=400, detail="Usuário já existe.")

    # Gera hash da senha
    hashed = hash_password(user.password)
    new_user = User(username=user.username, password_hash=hashed) # Cria um user

    # Salva no banco
    db.add(new_user)
    db.commit()
    db.refresh(new_user)

    return {"id": new_user.id, "username": new_user.username}


# LOGIN
@app.post("/login")
def login(user: UserLogin, db: Session = Depends(get_db)):
    # Busca usuário no banco
    user_db = db.query(User).filter(User.username == user.username).first()

    if not user_db:
        raise HTTPException(status_code=400, detail="Usuário não existe.")
    
    # Verifica senha
    if not verify_password(user.password, user_db.password_hash):
        raise HTTPException(status_code=401, detail="Senha incorreta.")

    # Cria token contendo o username
    token = create_access_token({"sub": user.username})

    return {
        "access_token": token,
        "token_type": "bearer"
    }


# ROTA PROTEGIDA
# Retorna o usuário atual, extraído do token.
@app.get("/me")
def me(username: str = Depends(verify_token)):
    return {"user": username}


# LISTAR USUÁRIOS
# Retorna todos os usuários cadastrados.
# O front-end usará isso para montar a lista de contatos.
@app.get("/users")
def list_users(username: str = Depends(verify_token), db: Session = Depends(get_db)):
    users = db.query(User).all()
    return [{"id": u.id, "username": u.username} for u in users]


# ROTA USADA PELO CHAT
# Chamado pelo ChatService para validar tokens.
# Se o token está correto, retorna o username.
@app.get("/verify-token")
def verify_token_public(username: str = Depends(verify_token)):
    print("Verificação do token pelo Chat")
    return {"user": username}


