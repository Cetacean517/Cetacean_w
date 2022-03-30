#!/usr/bin/python3.9
# @Time    : 2022/3/30 11:55
# @Author  : Cetacean
# @File    : SecureGetUser.py

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