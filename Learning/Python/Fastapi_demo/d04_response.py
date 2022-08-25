#!/usr/bin/python3.9
# @Time    : 2022/3/27 13:33
# @Author  : Cetacean
# @File    : d04_response.py

from fastapi import FastAPI
from fastapi.responses import JSONResponse, HTMLResponse, FileResponse

app = FastAPI()


@app.get("/user")
def getUser():
    # content:返回内容
    # status_code 设置状态码：202，
    # headers: 在头部设置返回内容
    return JSONResponse(content={"msg": "get user"},
                        status_code=202,
                        headers={"token": "abc"})


@app.get("/")
def web():
    # 创建一个html变量
    htmlcontent = '''
    <html>
        <body><p style="color:blue">Hello World</p></body>
    </html>
    '''
    # 返回html网页
    return HTMLResponse(content=htmlcontent)


@app.get("/avatar_download")
def avatar_download():
    imgurl = "static/doramo.jpg"
    # imgurl: 文件的地址
    # filename: 文件名称 （设置后，网页会直接下载文件）
    return FileResponse(imgurl, filename="doramo.jpg")


@app.get("/avatar_show")
def avatar_show():
    # imgurl = "static/doramo.jpg"
    imgurl = "static/PIC.txt"
    # imgurl: 文件的地址
    # filename: 文件名称 （不设置，直接在网页上显示该文件的信息）
    return FileResponse(imgurl)
