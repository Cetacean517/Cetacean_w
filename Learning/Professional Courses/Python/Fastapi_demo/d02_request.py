#!/usr/bin/python3.9
# @Time    : 2022/3/27 12:08
# @Author  : Cetacean
# @File    : d02_request.py.py

from fastapi import FastAPI

app = FastAPI()

# 发送post请求
@app.post("/login")
def login():
    return {"msg": "login success"}

# 支持多种类型的访问
@app.api_route("/login_both", methods=("GET", "POST", "PUT"))
def login_both():
    return {"msg": "login_both success"}
