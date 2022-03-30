# FASTAPI 学习笔记

## Lesson1 FastAPI 安装

1. 创建虚拟环境：Pycharm -- setting -- project -- add new environment

   能够使得该文件下的环境，不受系统环境的干扰。

2. 安装方法
   1. Pycharm安装：在虚拟环境中添加 fastapi 的包
   2. terminal安装：
      1. venv\Scripts\activate.bat （2 和 3 根据情况安装）
      2. pip install fastapi [all]  // 安装所有
      3. pip install fastapi // 安装最小情况

## Lesson2 开启服务和访问接口

1. 导入fastapi, 并创建程序对象

2. 开启服务：

   1. 使用`uvicorn.run(fastapi对象的名称)`
   2. 在terminal中，输入uvicorn
      1. `uvicorn 模块名：对象名 --reload`: `uvicorn d01_quickstart:app --reload`
         - reload: 热部署

3. 添加首页：

   ```python
   # 使用装饰器，将下面的string渲染在主页
   @app.get("/")
   def index():
       return "This is home page."
   ```

## Lesson3 JSON数据返回 和 自动生成文档

1. 返回不同类型的数据

   1. JSON格式输出

   ```python
   # 2. 返回json格式数据
   @app.get("/json")
   def user():
       """ 返回学生信息字典"""
       return {"Lily": 18, "Winnie": 30}
   ```

   2. 数组格式输出

   ```python
   # 3. 返回列表
   @app.get("/list")
   def score():
       """ 返回 成绩列表"""
       return [90,88,45,13]
   ```

   

2. 查看文档（代码中的""""""包裹的注释会显示在文档中）：
   1. url = 127.0.0.1/docs（swagger风格的接口文档）
   2. url = 127.0.0.1/redoc

## Lesson4 发送POST请求

1. 处理post请求的接口

   ```python
   # 发送post请求
   @app.post("/login")
   def login():
       return {"msg": "login success"}
   ```

2. 处理多种请求的接口

   ```python
   # 支持多种类型的访问
   @app.api_route("/login_both", methods=("GET", "POST", "PU"))
   def login_both():
       return {"msg": "login_both success"}
   ```

## Lesson5 获取GET请求参数

1. get的带参数传递

   1. '/' + 参数值

   ```python
   # 请求url = localhost:8000/user/8
   @app.get("/user/{id}")
   def user_1(id):
       return {"Id": id}
   ```
2. '?' + 参数=参数值
   ```python
   # 请求url = localhost:8000/user/?id=8
	@app.get("/user")
	def user_2(id):
    return {"Id": id}
   ```
	
## Lesson6 获取POST请求参数，以及请求头中的参数

1. 获取请求头中的token参数

   ```python
   # 请求头中需要设置token=“”
   # 请求url中设置参数
   @app.get("/token")
   def getToken(id, token=Header(None)):
       return {"id": id, "token": token}
   ```

2. 获取POST请求的请求体 Json格式

   ```python
   # 获取post请求的请求体(json格式)
   # 发送json格式的body数据
   @app.post("/login_body")
   def getBody(data=Body(None)):
       return {"data": data}
   ```

3. 获取POST请求的请求体 form表单格式

   ```python
   # 获取post请求的请求体(form表单格式)
   @app.post("/login_body_form")
   def getBody(username=Form(None), password=Form(None)):
       return {"data": {"username": username, "password": password}}
   ```

## Lesson7 返回图片和定制返回信息

1. JSONResponse: 返回json格式, 并修改状态码信息

   ```python
   @app.get("/user")
   def getUser():
       # content:返回内容
       # status_code 设置状态码：202，
       # headers: 在头部设置返回内容
       return JSONResponse(content={"msg": "get user"},
                           status_code=202,
                           headers={"token": "abc"})
   ```

   

2. HTMLResponse：返回html文档

   ```python
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
   ```

3. FileResponse：返回文件

   - 返回：直接下载返回的文件

     ```python
       @app.get("/avatar_download")
       def avatar_download():
           imgurl = "static/doramo.jpg"
           # imgurl: 文件的地址
           # filename: 文件名称 （设置后，网页会直接下载文件）
           return FileResponse(imgurl, filename="doramo.jpg")
     ```

   - 返回：页面显示返回的文件

     ```python
     @app.get("/avatar_show")
     def avatar_show():
         # imgurl = "static/doramo.jpg"
         imgurl = "static/PIC.txt"
         # imgurl: 文件的地址
         # filename: 文件名称 （不设置，直接在网页上显示该文件的信息）
         return FileResponse(imgurl)
     ```

     

## Lesson8 jinjia2模板返回HTML页面

文件目录结构

```
-pages	// 存放所有的html文件
	-- index.html
-d05_templates.py // 返回html的python接口文件
```

模板返回html页面

```python
# html文件放在了pages里面

from fastapi import FastAPI, Request
from fastapi.templating import Jinja2Templates

app = FastAPI()
template = Jinja2Templates("pages")     # pages是存放html文件的文件夹名


@app.get("/")
def user(req: Request):
    # req(自定义的接受数据的参数名)：Request 接受的参数(astapi的一个包)
    # 返回参数:
    # "index.html": 返回的html文件名
    # content{"request":传入参数名}: 渲染的动态数据。
    return template.TemplateResponse("index.html", context={"request": req})
```

## Demo1：前后端不分离的todoList
功能：
- 输入想要增加的课程，并在网页上动态渲染

文件目录结构：

```
-pages	// 存放所有的html文件
	-- index.html
-d06_templates_for.py // 返回html的python接口文件
```

1. html
   - python 中的 html for循环
   - 表单传递的设置

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>FastAPI</title>
</head>
<body>
    <div>
        <h1>Curriculum to Learn</h1>
        <div>
<!--            action: 设置传递的api; method: 设置传递的方法-->
            <form action="/class" method="POST">
<!--                设置name属性：后端根据name属性接受数据-->
                <input name="data" placeholder="Please enter a course:">
                <input type="submit" value="添加">
            </form>
        </div>
<!--  python 中的 for 循环      -->
        {% for c in courses%}
        <p>{{c}}</p>
        {% endfor %}
    </div>
</body>
</html>
```

2. python 文件

```python
   from fastapi import FastAPI, Request, Form
   from fastapi.responses import RedirectResponse
   from fastapi.templating import Jinja2Templates
   
   app = FastAPI()
   templates = Jinja2Templates("pages")
   
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
       # 状态码 302：可以
       return RedirectResponse("/", status_code=302)
```

 ## Demo2: 连接数据库：搜索和增加

### 项目逻辑:

- template渲染前端页面
- dao中存放数据库的表
- 利用fastapi：
  - 获取前端数据，存入数据库；
  - 对数据库中的数据进行搜索，并返回给前端

### 文件目录结构：

```
-pages	// 存放所有的html文件
	-- index.html
	-- search_result.html
-dao  // 存放数据库中的表(python directory)
	-- models.py
-d07_tortoise_orm.py // 处理前端和数据库之间的api接口
```

### 代码部分

#### html 文件（略）

#### models.py （dao）

- 新建的表单类，继承Model类
- 设置主键
- 创建和修改时间

```python
from tortoise import Model, fields


# TODO类继承Model类
class Todo(Model):
    """数据库当中的表 todo"""
    id = fields.IntField(pk=True)  # 整型字段，并设为主键(pk)
    content = fields.CharField(max_length=500)  # 内容，设置最大长度
    created_at = fields.DatetimeField(auto_now_add=True)  # 创建时间,插入新数据才更新
    updated_at = fields.DatetimeField(auto_now=True)  # 修改时间，每一次修改就更新
```

#### d07_torotise_orm.py

- 初始化，以及数据库绑定
- register_tortoise:
  - app: `FASTAPI() 函数名`
  - db_url 格式:  `数据库名://用户名:密码@url地址:端口号/数据库名`
  - modules : 设置模型类  `{"models": ['模型类的地址']}`
  -  add_exception_handlers=True： 处理异常
  - generate_schemas=True：生成数据结构

```python
from fastapi import FastAPI, Request, Form
from fastapi.responses import RedirectResponse
from fastapi.templating import Jinja2Templates
from tortoise.contrib.fastapi import register_tortoise

from dao.models import Todo

app = FastAPI()
templates = Jinja2Templates("pages")

# 数据库绑定
# db_url 格式:数据库名://用户名:密码@url地址:端口号/数据库名
register_tortoise(app, db_url="mysql://root:root@localhost:3306/fastapi",
                  modules={"models": ['dao.models']},  # 设置模型类：用类代替sql语句
                  add_exception_handlers=True,  # 处理异常
                  generate_schemas=True  # 生成数据结构
                  )
```

- 接口处理
  - 用异步执行

```python
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
```

# 安全性

## Security - First Steps

前后端登录逻辑

1. 用户在网页（前端）输入**密码**和**用户名**。
2. 前端发送，{密码，用户名} 给后端的接口 （指定`tokenUrl = "token"`)
3. 后端API检查 {密码，用户名}，返回token
4. 前端存储token。
5. 用户从一个网页跳转到，前端的另一个网页
6. 前端需要从API获取其他的数据
   1. 获取API的授权
   2. 发送 `Authorization : Bearer + token`
   3. 当token 包含`foobar`, `Ahthorization`头会是：`Bearer foobar`

## FastAPI's OAuth2PasswordBearer

(使用OAuth2，密码流，以及Bearer token 实现登录场景)

#### 快速Demo：获取token的接口

1. 传入参数：tokenUrl = "token" 
   1. token是一个相对URL，= './token'
   2. 没有创建一个路径函数，只是声明用户从/token获取token

```python
from fastapi import Depends, FastAPI
from fastapi.security import OAuth2PasswordBearer

app = FastAPI()

oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")

# 使用了依赖
@app.get("/items/")
async def read_items(token: str = Depends(oauth2_scheme)):
    return {"token": token}

```

#### 获取当前用户

- 创建用户模型
- 通过依赖获取token，并获取对象实例
- 注入当前用户

```python
from typing import Optional

from fastapi import Depends, FastAPI
from fastapi.security import OAuth2PasswordBearer
from pydantic import BaseModel

app = FastAPI()

oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")

# 1. 创建用户模型
class User(BaseModel):
    username: str
    email: Optional[str] = None
    full_name: Optional[str] = None
    disabled: Optional[bool] = None

# 
def fake_decode_token(token):
    return User(
        username=token + "fakedecoded", email="john@example.com", full_name="John Doe"
    )

# 2. 创建 get_current_user 的依赖项
# 2.1 从 oauth2_sheme 获取token
# 2.2 利用fake_decode_token 创建一个用户实例
# 2.3 返回user实例
async def get_current_user(token: str = Depends(oauth2_scheme)):
    user = fake_decode_token(token)
    return user

# 3. 注入当前用户
@app.get("/users/me")
async def read_users_me(current_user: User = Depends(get_current_user)):
    return current_user

```

## 使用密码和Bearer的简单登录

#### 获取 username 和 password

规范还写明了 `username` 和 `password` 必须作为表单数据发送（因此，此处不能使用 JSON）。

scope

- 这个表单字段的名称为 `scope`（单数形式），但实际上它是一个由空格分隔的「作用域」组成的长字符串。

- 每个「作用域」只是一个字符串（中间没有空格）。
- 它们通常用于声明特定的安全权限，例如：
  - `users:read` 或者 `users:write` 是常见的例子。



