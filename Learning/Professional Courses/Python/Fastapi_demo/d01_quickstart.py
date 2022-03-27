#!/usr/bin/python3.9

# @Time    : 2022/3/27 11:44
# @Author  : Cetacean
# @File    : d.py

# 导入 fastspi
from fastapi import FastAPI
import uvicorn

app = FastAPI()


# 1. 返回字符串
@app.get("/")
def index():
    """ 返回主页内容 """
    return "This is home page."


# 2. 返回json格式数据
@app.get("/json")
def user():
    """ 返回学生信息字典"""
    return {"Lily": 18, "Winnie": 30}

# 3. 返回列表
@app.get("/list")
def score():
    """ 返回 成绩列表"""
    return [90,88,45,13]

if __name__ == "__main__":
    uvicorn.run(app)
