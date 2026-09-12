from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
import itertools
import asyncio
import httpx

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# Lista das instâncias
INSTANCES = [
    {"http_url": "http://localhost:8001", "ws_url": "ws://localhost:8001", "up": True},
    {"http_url": "http://localhost:8002", "ws_url": "ws://localhost:8002", "up": True},
    {"http_url": "http://localhost:8003", "ws_url": "ws://localhost:8003", "up": True},
]

# Round-robin
rr = itertools.cycle(INSTANCES)

@app.get("/choose")
def choose_instance():
    alive = [s for s in INSTANCES if s["up"]]

    if not alive:
        return {"error": "No instances available"}

    # Pega próximo do round-robin até achar um servidor vivo
    for _ in range(len(INSTANCES)):
        instance = next(rr)  # usa o round-robin GLOBAL
        if instance["up"]:
            return instance

    return {"error": "No instances available"}

@app.on_event("startup")
async def startup():
    asyncio.create_task(check_instances())

async def check_instances():
    while True:
        for instance in INSTANCES:
            url = instance["http_url"] + "/health"

            try:
                async with httpx.AsyncClient(timeout=1) as client:
                    r = await client.get(url)
                    instance["up"] = (r.status_code == 200)
            except:
                instance["up"] = False

        await asyncio.sleep(2)  # verifica a cada 2 segundos