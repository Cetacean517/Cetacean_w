#coding:utf-8
## -*- coding : gbk -*-

##from __future__ import print_function
from math import pi as PI
import types
import collections
import random
import math
import fractions
import os
import copy
import re

class Car:
    price = 100000  #定义类属性
    def __init__(self, c):
        self.color = c #定义实例属性

def setSpeed(self,s):
    self.speed=s

def f1():
    import types
    car1 = Car("Red")
    car2 = Car("Blue")
    print(car1.color, Car.price)    
    Car.price = 110000 #修改类属性
    Car.name = 'QQ' #增加类属性
    car1.color = "Yellow" #修改实例属性
    print(car2.color, Car.price, Car.name)
    print(car1.color, Car.price, Car.name)
    #动态增加类成员函数
    car1.setSpeed=types.MethodType(setSpeed,Car)
    car1.setSpeed(50)
    print(car1.speed)

#函数和方法的区别
class Demo:
    pass

def test(self, v):
    self.value = v

def f11():
    t=Demo()
    t.test = test
    print(t.test)
    t.test(t,3)
    print(t.value)
    t.test = types.MethodType(test, t)
    print(t.test)
    t.test(5)
    print(t.value)
    
#成员类型的例示
class A:
    def __init__(self, value1 = 0, value2 = 0):
        self._value1 = value1
        self.__value2 = value2
    def setValue(self, value1, value2):
        self._value1 = value1
        self.__value2 = value2
    def show(self):
        print(self._value1)
        print(self.__value2)

class Fruit:
        def __init__(self):
             self.__color = 'Red'
             self.price = 1

def f2():
    a = A()
    print(a._value1)
    print(a._A__value2) #在外部访问对象的私有数据成员

    apple = Fruit()
    print(apple.price) #显示对象公开数据成员的值
    apple.price = 2 #修改对象公开数据成员的值
    print(apple.price, apple._Fruit__color) #显示对象私有数据成员的值

    apple._Fruit__color = "Blue" #修改对象私有数据成员的值
    print(apple.price, apple._Fruit__color)
    peach = Fruit()
    print(peach.price, peach._Fruit__color)

    print(apple.__color) #不能直接访问对象的私有数据成员，出错

#类方法和静态方法
class Root:
    __total = 0
    def __init__(self, v):
        self.__value = v
        Root.__total += 1

    def show(self):
        print('self.__value:', self.__value)
        print('Root.__total:', Root.__total)

    @classmethod
    def classShowTotal(cls): #类方法
        print(cls.__total)

    @staticmethod
    def staticShowTotal(): #静态方法
        print(Root.__total)

def f3():
    r = Root(3)
    r.classShowTotal() #通过对象来调用类方法
    r.staticShowTotal() #通过对象来调用静态方法
    r.show()

    rr = Root(5)
    Root.classShowTotal() #通过类名调用类方法
    Root.staticShowTotal() #通过类名调用静态方法

    r.show()
    rr.show()
    #可以通过这种方法来调用方法并访问实例成员
    Root.show(r) 
     #通过类名调用实例方法时为self参数显式传递对象名
    Root.show(rr)
    Root.show() #试图通过类名直接调用实例方法，失败

def sep():
    print('\n===============')
    print('@@@@@@@@@')
    print('===============\n')

def main():
    f1()
    sep()
    f11()
    sep()
    f2()
    sep()
    f3()
    
main()
