# launcher.py
import subprocess, time, sys

peers = [
    {"port":5000, "args":["--ip","127.0.0.1","--port","5000","--file","arquivo_20mb.txt"]},
    {"port":5001, "args":["--ip","127.0.0.1","--port","5001","--neighbors","127.0.0.1:5000,127.0.0.1:5002,127.0.0.1:5003","--arquivo_desejado","arquivo_20mb.txt"]},
    {"port":5002, "args":["--ip","127.0.0.1","--port","5002","--neighbors","127.0.0.1:5000,127.0.0.1:5001,127.0.0.1:5003","--arquivo_desejado","arquivo_20mb.txt"]},
    {"port":5003, "args":["--ip","127.0.0.1","--port","5003","--neighbors","127.0.0.1:5000,127.0.0.1:5001,127.0.0.1:5002","--arquivo_desejado","arquivo_20mb.txt"]},
]



procs = []
for p in peers:
    cmd = [sys.executable, "peer.py"] + p["args"]
    proc = subprocess.Popen(cmd)
    procs.append(proc)
    time.sleep(0.4)

print("Press Ctrl+C to stop.")
try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    print("Stopping")
    for proc in procs:
        proc.terminate()