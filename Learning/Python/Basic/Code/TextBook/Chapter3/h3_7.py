"""7. 编写程序，至少使用两种不同的方法计算100以内所以奇数的和。"""
from functools import reduce
from random import random

"""利用sum函数"""


def method1():
    return sum([i for i in range(1, 100, 2)])


"""利用reduce函数"""


def method2():
    return reduce(lambda x, y: x + y, [i for i in range(1, 100, 2)])


"""利用if条件表达式"""


def method3():
    sum = 0
    i = 1
    while i < 100:
        sum += i
        i += 2
    return sum


print(method1())
print(method2())
print(method3())
