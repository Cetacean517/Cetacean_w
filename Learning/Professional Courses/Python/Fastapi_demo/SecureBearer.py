#!/usr/bin/python3.9
# @Time    : 2022/3/30 12:09
# @Author  : Cetacean
# @File    : SecureBearer.py

from typing import Optional

from fastapi import Depends, FastAPI, HTTPException, status
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm
from pydantic import BaseModel

# 伪数据库
fake_users_db = {
    "johndoe": {
        "username": "johndoe",
        "full_name": "John Doe",
        "email": "johndoe@example.com",
        "hashed_password": "fakehashedsecret",
        "disabled": False,
    },
    "alice": {
        "username": "alice",
        "full_name": "Alice Wonderson",
        "email": "alice@example.com",
        "hashed_password": "fakehashedsecret2",
        "disabled": True,
    },
}

app = FastAPI()


# 伪加密
def fake_hash_password(password: str):
    return "fakehashed" + password


# 指定从那个接口获取token
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")


# 用户模型
class User(BaseModel):
    username: str
    email: Optional[str] = None
    full_name: Optional[str] = None
    disabled: Optional[bool] = None


# 获取用户加哈希后的密码
class UserInDB(User):
    hashed_password: str


def get_user(db, username: str):
    if username in db:
        user_dict = db[username]
        return UserInDB(**user_dict)


def fake_decode_token(token):
    # This doesn't provide any security at all
    # Check the next version
    # 获取用户的实例
    user = get_user(fake_users_db, token)
    return user


async def get_current_user(token: str = Depends(oauth2_scheme)):
    user = fake_decode_token(token)
    if not user:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Invalid authentication credentials",
            headers={"WWW-Authenticate": "Bearer"},
        )
    return user


async def get_current_active_user(current_user: User = Depends(get_current_user)):
    if current_user.disabled:
        raise HTTPException(status_code=400, detail="Inactive user")
    return current_user


#
@app.post("/token")
async def login(form_data: OAuth2PasswordRequestForm = Depends()):
    # 通过用户名，获取数据库中的用户信息
    user_dict = fake_users_db.get(form_data.username)
    # 权限失败，反馈失败信息
    if not user_dict:
        raise HTTPException(status_code=400, detail="Incorrect username or password")
    # 创建用户实例
    user = UserInDB(**user_dict)    # user_dict的键和值作为关键字参数传递
    # 获取用户哈希密码
    hashed_password = fake_hash_password(form_data.password)
    # 判断密码是否一致
    if not hashed_password == user.hashed_password:
        raise HTTPException(status_code=400, detail="Incorrect username or password")
    # 返回令牌
    return {"access_token": user.username, "token_type": "bearer"}


@app.get("/users/me")
async def read_users_me(current_user: User = Depends(get_current_active_user)):
    return current_user
