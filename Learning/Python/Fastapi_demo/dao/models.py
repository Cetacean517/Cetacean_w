#!/usr/bin/python3.9
# @Time    : 2022/3/27 16:16
# @Author  : Cetacean
# @File    : models.py
from tortoise import Model, fields


# TODO类继承Model类
class Todo(Model):
    """数据库当中的表 todo"""
    id = fields.IntField(pk=True)  # 整型字段，并设为主键(pk)
    content = fields.CharField(max_length=500)  # 内容，设置最大长度
    created_at = fields.DatetimeField(auto_now_add=True)  # 创建时间,插入新数据才更新
    updated_at = fields.DatetimeField(auto_now=True)  # 修改时间，每一次修改就更新
