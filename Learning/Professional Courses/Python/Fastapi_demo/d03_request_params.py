#!/usr/bin/python3.9
# @Time    : 2022/3/27 12:22
# @Author  : Cetacean
# @File    : d03_request_params.py
from fastapi import FastAPI, Header, Body, Form

app = FastAPI()


# 请求url = localhost:8000/user/8
@app.get("/user/{id}")
def user_1(id):
    return {"Id": id}


# 请求url = localhost:8000/user/?id=8
@app.get("/user")
def user_2(id):
    return {"Id": id}


# 请求头中需要设置token=“”
# 请求url中设置参数
@app.get("/token")
def getToken(id, token=Header(None)):
    return {"id": id, "token": token}


# 获取post请求的请求体(json格式)
@app.post("/login_body")
def getBody(data=Body(None)):
    return {"data": data}


# 获取post请求的请求体(form表单格式)
@app.post("/login_body_form")
def getBody(username=Form(None), password=Form(None)):
    return {"data": {"username": username, "password": password}}
