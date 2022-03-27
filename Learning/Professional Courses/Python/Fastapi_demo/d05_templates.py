#!/usr/bin/python3.9
# @Time    : 2022/3/27 14:51
# @Author  : Cetacean
# @File    : d05_templates.py

# html文件放在了pages里面

from fastapi import FastAPI, Request
from fastapi.templating import Jinja2Templates

app = FastAPI()
template = Jinja2Templates("pages_05")     # pages是存放html文件的文件夹名


@app.get("/")
def user(req: Request):
    # req(自定义的接受数据的参数名)：Request 接受的参数(astapi的一个包)
    # 返回参数:
    # "index.html": 返回的html文件名
    # content{"request":传入参数名}: 渲染的动态数据。
    return template.TemplateResponse("index.html", context={"request": req})
