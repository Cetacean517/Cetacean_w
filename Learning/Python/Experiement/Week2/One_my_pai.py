import math
from decimal import Decimal  # 精于计算 引入了Decimal的库，其中包含了很多关于小数的处理方式
from decimal import getcontext  # 保留的小数位数，自己设置
import time  # 用于测试
import numpy as np


# np.set_printoptions(suppress=True)  # 取消科学计数法输出


# def Pai(max):
#     getcontext().prec = 16  # 设置数有几位，由于个为有1位，小数15位，故设置一共16位
#     sum1 = Decimal()
#     my_pai = Decimal(0)
#     k = 0
#     while k < Decimal(max):
#         sum1 = Decimal(1103) + Decimal(26390 * k)       # 求和
#         for i in range(k, 0, -1):                       # * k!
#             sum1 = Decimal(sum1) * Decimal(i)
#         for j in range(4 * k, 0, -1):                   # /4k! /(396)**(4k)
#             sum1 = Decimal(sum1) / Decimal(j) / Decimal(396)
#         my_pai += sum1
#         k += 1
#
#     my_pai = Decimal(my_pai) * Decimal(2) * Decimal(math.sqrt(2) / 9801)
#     my_pai = Decimal(1) / Decimal(my_pai)
#     return my_pai

'''2.0 利用math库，精确度提升'''
def Pai(max):
    getcontext().prec = 16  # 设置数有几位，由于个为有1位，小数15位，故设置一共16位
    k = 0
    m = 2 * math.sqrt(2) / 9801
    sum = 0
    while k < max:
        top = math.factorial(4 * k) * (1103 + 26390 * k)
        bottom = math.factorial(k) ** 4 * (396) ** (4 * k)
        sum = sum + top / bottom
        k += 1
    sum = 1 / (sum * m)
    return sum



if __name__ == '__main__':
    print('\nk = 100: ')
    print(math.pi)
    start = time.time()
    print(Pai(100))
    print('time_delta:', time.time() - start)

    print('\nk = 500: ')
    print(math.pi)
    start = time.time()
    print(Pai(500))
    print('time_delta:', time.time() - start)

    print('\nk = 1000: ')
    print(math.pi)
    start = time.time()
    print(Pai(1000))
    print('time_delta:', time.time() - start)

    print('\nk = 3000: ')
    print(math.pi)
    start = time.time()
    print(Pai(3000))
    print('time_delta:', time.time() - start)

    print('\nk = 5000: ')
    print(math.pi)
    start = time.time()
    print(Pai(5000))
    print('time_delta:', time.time() - start)

    print('\nk = 8000: ')
    print(math.pi)
    start = time.time()
    print(Pai(8000))
    print('time_delta:', time.time() - start)

'''k = 100: 
3.141592653589793
3.141592653589793
time_delta: 0.001993417739868164
k = 500: 
3.141592653589793
3.141592653589793
time_delta: 0.0927882194519043
k = 1000: 
3.141592653589793
3.141592653589793
time_delta: 0.6557834148406982
k = 3000: 
3.141592653589793
3.141592653589793
time_delta: 11.246943712234497
k = 5000: 
3.141592653589793
3.141592653589793
time_delta: 45.068578243255615
k = 8000: 
3.141592653589793
3.141592653589793
time_delta: 174.3001811504364
'''