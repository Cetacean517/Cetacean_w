""" 6.3 属性"""
"""6.3.1 Python 2.x 中的属性"""

# # 廖雪峰 @property的使用 补充
# class Student(object):
#     def __init__(self, name):
#         self._name = name
#     '''属性的作用：我们在对实例属性操作的时候，就知道该属性很可能不是直接暴露的，而是通过getter和setter方法来实现的。'''
# # 设置name的get属性
#     @property
#     def name(self):
#         return self._name
#
#     @name.setter
#     def name(self, name):
#         if isinstance(name, str):
#             self._name = name
#         else:
#             print('type error!!!')
#
#     def show(self):
#         print(self._name)
#
#
# s = Student('wendy')
# s.show()
# s.name = 'lily'  # 相当于s._name = 'lily' ,但是调用的name的set函数;增加了对于输入值的判断
# print(s.name)    # 相当于s._name, 调用的name的get函数。
# s.name = 1      # 通过name的set函数判断输入类型不合理，所以没有进行对象成员的修改。
# print(s.name)
# print(dir(s))
''' 6.3.1 Python 3.x 中的属性'''
# class Test:
#     def __init__(self, value):
#         self.__value = value
#
#     @property
#     def value(self):  # 只读，无法修改和删除
#         return self.__value
#
#
# t = Test(3)
# print(t.value)
# # 3
# # t.value = 5  # 只读属性不允许修改值
# # AttributeError: can't set attribute
# t.v = 5  # 动态增加新成员
# print(t.v)
# del t.v  # 动态删除成员
# # print(t.v)  # 成功删除成员
# # AttributeError: 'Test' object has no attribute 'v'
# # del t.value  # 试图删除对象属性，失败
# # AttributeError: can't delete attribute
# print(t.value)   # 显示属性值
# # 3

# ''' 把属性设置为可读，可修改，而不允许删除。'''
#
#
# class Test:
#     def __init__(self, value):
#         self.__value = value
#
#     def __get(self):
#         return self.__value
#
#     def __set(self, v):
#         self.__value = v
#
#     value = property(__get, __set)
#
#     def show(self):
#         print(self.__value)
#
#
# t = Test(3)
# print(t.value)  # 允许读取属性值
# # 3
# t.value = 5  # 允许修改属性值
# print(t.value)
# # 5
# t.show()  # 属性对应的私有变量也得到了相应的修改
# # 5
# '''del t.value  # 试图删除属性，失败
# # AttributeError: can't delete attribute'''

# ''' 把属性设置为可读，可修改，可删除。'''
#
#
# class Test:
#     def __init__(self, value):
#         self.__value = value
#
#     def __get(self):
#         return self.__value
#
#     def __set(self, v):
#         self.__value = v
#
#     def __del(self):
#         del self.__value
#
#     value = property(__get, __set, __del)
#
#     def show(self):
#         print(self.__value)
#
#
# t = Test(3)
# t.show()
# # 3
# t.value = 5
# t.show()
# # 5
# del t.value
# ''' # 删除了对象的属性
# print(t.value)
# #AttributeError: 'Test' object has no attribute '_Test__value'
# t.show()
# #AttributeError: 'Test' object has no attribute '_Test__value'
# '''
# t.value = 1  # 为对象动态增加属性和对应的私有数据成员
# t.show()
# # 1
# print(t.value)
# # 1
