#!/usr/bin/python3.9
# @Time    : 2022/3/27 15:16
# @Author  : Cetacean
# @File    : d06_templates_demo.py.py
from fastapi import FastAPI, Request, Form
from fastapi.responses import RedirectResponse
from fastapi.templating import Jinja2Templates

app = FastAPI()
templates = Jinja2Templates("pages_06")

# 全局的数据区
courses = ["C++ Beginner", "Python Thinker", "DataBase"]


@app.get("/")
def login(req: Request):
    return templates.TemplateResponse("index.html", context={"request": req, "courses": courses})


@app.post("/class")
def todo(data=Form(None)):
    """处理用户增加的 courses列表的课程"""
    courses.insert(0, data)
    # 状态码 307：不能从POST请求跳转到GET请求
    # 状态码 302：可以从POST
    return RedirectResponse("/",status_code=302)
