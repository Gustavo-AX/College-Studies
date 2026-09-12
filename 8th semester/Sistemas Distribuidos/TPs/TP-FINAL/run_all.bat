@echo off
title Inicializando Sistema Distribuido

echo ============================================
echo INICIANDO CANAL GLOBAL (PORTA 9000)
echo ============================================
start cmd /k "cd channel && py -m uvicorn main:app --reload --host 0.0.0.0 --port 9000"

timeout /t 2 >nul

echo ============================================
echo INICIANDO SERVICO DE AUTENTICACAO (PORTA 8000)
echo ============================================
start cmd /k "cd authentication && py -m uvicorn main:app --reload --port 8000"

timeout /t 2 >nul

echo ============================================
echo INICIANDO SERVICO DE CHAT (PORTAS 8001,8002,8003)
echo ============================================
start cmd /k "cd chat && py -m uvicorn main:app --reload --port 8001"
timeout /t 1 >nul
start cmd /k "cd chat && py -m uvicorn main:app --reload --port 8002"
timeout /t 1 >nul
start cmd /k "cd chat && py -m uvicorn main:app --reload --port 8003"

timeout /t 2 >nul

echo ============================================
echo INICIANDO BALANCER (PORTA 9001)
echo ============================================
start cmd /k "cd front && py -m uvicorn balancer:app --reload --port 9001"

timeout /t 2 >nul

echo ============================================
echo INICIANDO FRONT-END (PORTAS 5500,5501,5502)
echo ============================================
start cmd /k "cd front && py -m http.server 5500"
start cmd /k "cd front && py -m http.server 5501"
start cmd /k "cd front && py -m http.server 5502"
start cmd /k "cd front && py -m http.server 5503"

echo ============================================
echo Todos os serviços foram iniciados!
echo Acesse as UIs:
echo  - http://127.0.0.1:5500/login.html
echo  - http://127.0.0.1:5501/login.html
echo  - http://127.0.0.1:5502/login.html
echo  - http://127.0.0.1:5503/login.html

echo ============================================

pause
