# app/main.py
from fastapi import FastAPI

app = FastAPI()

@app.get("/")
def read_root():
    return {"Hello": "green-2"}

@app.get("/health")
def read_health():
    return {"status": "green"}
@app.get("/health/wonderful")
def read_health():
    return {"status": "green"}