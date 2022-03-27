#!/usr/bin/python3.9
# @Time    : 2022/3/27 15:57
# @Author  : Cetacean
# @File    : d07_tortoise_orm.py

from fastapi import FastAPI, Request, Form
from fastapi.responses import RedirectResponse
from fastapi.templating import Jinja2Templates
from tortoise.contrib.fastapi import register_tortoise

from dao.models import Todo

app = FastAPI()
templates = Jinja2Templates("pages")

# 数据库绑定
# db_url 格式:数据库名://用户名:密码@url地址:端口号/
register_tortoise(app, db_url="mysql://root:root@localhost:3306/fastapi",
                  modules={"models": ['dao.models']},  # 设置模型类：用类代替sql语句
                  add_exception_handlers=True,  # 处理异常
                  generate_schemas=True  # 生成数据结构
                  )


# 使用异步执行数据库加载数据
@app.get("/")
async def index(req: Request):
    # 从数据库获取 todos 的代码
    # ORM，获取所有的todos
    todos = await Todo.all()
    return templates.TemplateResponse("index.html", context={"request": req, "todos": todos})


@app.post("/todo")
async def todo(content=Form(...)):
    """处理用户增加的 courses列表的课程"""
    # 把新的事项存储到数据库中
    await Todo(content=content).save()
    return RedirectResponse("/", status_code=302)


@app.post("/search")
async def search(req: Request, keyword=Form(None)):
    # 查询包含keyword的所有记录
    # content__icontains:content字段中包含keyword的部分
    search_results = await Todo.filter(content__icontains=keyword).all()
    return templates.TemplateResponse("search_result.html",
                                      context={"request": req,
                                               "search_results": search_results})
