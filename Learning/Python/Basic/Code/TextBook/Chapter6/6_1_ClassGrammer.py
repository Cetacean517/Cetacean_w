# """6.1.1 类的定义与使用"""
#
#
# class Car:  # 新式类必须有至少一个基类
#     """ 创建一个类并实例化"""
#
#     def infor(self):
#         print("This is a car")
#
#
# car = Car()
# car.infor()  # 通过对象名调用方法。
#
# print(isinstance(car, Car))
# print(isinstance(car, str))
#
#
# class A:
#     pass
#
#
# def demo():
#     pass
#
#
# if 5 > 3:
#     pass
#
# """6.1.2 self参数"""
#
#
# class A:
#     def __init__(lalala, v):
#         lalala.value = v
#
#     def show(lalala):
#         print(lalala.value)
#
#
# a = A(3)
# a.show()

# """6.1.3 类成员和实例成员"""
# import types
#
#
# class Car:
#     price = 100000  # 定义类属性
#
#     def __init__(self, c):
#         self.color = c  # 定义实例属性
#
#
# car1 = Car('Red')
# car2 = Car('Blue')
# print(car1.color, Car.price)
# # Red 100000 创建实例成功
# Car.price = 110000  # 修改类属性，通过类名访问
# Car.name = "QQ"  # 增加类属性
# car1.color = "Yellow"  # 修改实例属性，通过对象名访问
# print(car2.color, Car.price, Car.name)
# # Blue 110000 QQ 可以通过对象名.属性名/类名.属性名的形式访问数据成员
# print(car1.color, Car.price, Car.name)
# # Yellow 110000 QQ
# print(car1.color, car1.price, car1.name)
#
#
# # Yellow 110000 QQ
#
#
# def setSpeed(self, s):
#     self.speed = s
#
#
# car1.setSpeed = types.MethodType(setSpeed, Car)  # 动态为对象增加成员方法
# car1.setSpeed(50)
# print(car1.speed)
#
#
# # 50 可以动态的为对象增加成员方法要使用types的MethodType方法
#
# def addMethod():
#     car2.setSpeed = setSpeed  # 把setSpeed函数赋给car2的一个成员变量
#     print(car2.setSpeed)  # 此时setSpeed只是在内存中的一个函数
#     # <function setSpeed at 0x0000019EE6724700>
#     car2.setSpeed(car2, 50)  # 调用setSpeed(self,s)函数需要传入self指针和s数值
#     print(car2.speed)
#     # 50
#     car2.setSpeed = types.MethodType(setSpeed, Car)  # 动态为对象增加成员方法
#     print(car2.setSpeed)  # 此时setSpeed函数是类内部的一个方法
#     # <bound method setSpeed of <class '__main__.Car'>>
#     car2.setSpeed(50)  # 通过对象名设置数据成员的数值
#     print(car2.speed)
#     # 50
#
#
# addMethod()

# """6.1.4 私有成员与公有成员"""
#
#
# class A:
#     def __init__(self, value1=0, value2=0):
#         self._value1 = value1
#         self.__value2 = value2
#
#     def setValue(self, value1, value2):
#         self._value1 = value1
#         self.__value2 = value2
#
#     def show(self):
#         print(self._value1)
#         print(self.__value2)
#
#
# a = A()
# print(a._value1)    # _value1只是保护成员
# print(a._A__value2)  # __value2是私有成员，不能直接访问。在外部访问对象的私有成员
#                     #  特殊方法：对象名._类名__私有成员名
#
# class Fruit:
#     def __init__(self):
#         self.__color = 'Red'
#         self.price = 1
#
#
# apple = Fruit()
# print(apple.price)  # 显示对象公开数据成员的值
# # 1
# apple.price = 2  # 修改对象公开数据成员的值
# print(apple.price)
# # 2 apple的公开数据成员被修改
# print(apple.price, apple._Fruit__color)  # 显示对象私有数据成员的值
# # 2 Red 显示apple的私有数据成员
# apple._Fruit__color = 'Blue'  # 修改对象私有数据成员的值
# print(apple.price, apple._Fruit__color)
# # 2 Blue 私有成员被修改
# # print(apple.__color)
# # AttributeError: 'Fruit' object has no attribute '__color'
# # 私有成员不能直接被访问
# peach = Fruit()
# print(peach.price,peach._Fruit__color)
# # 1 Red 对于对象私有成员和共有成员的修改只是针对该对象，而不影响类的私有/共有成员函数
