import math
from decimal import Decimal     # 精于计算 引入了Decimal的库，其中包含了很多关于小数的处理方式
from decimal import getcontext  # 保留的小数位数，自己设置
import time # 用于测试
import numpy as np


np.set_printoptions(suppress=True)  # 取消科学计数法输出


def Pai(max):
    getcontext().prec = 16  # 设置数有几位，由于个为有1位，小数15位，故设置一共16位
    sum1 = Decimal()
    my_pai = Decimal(0)
    k = 0
    while k < Decimal(max):
        sum1 = Decimal(1103) + Decimal(26390 * k)       # 求和
        for i in range(k, 0, -1):                       # * k!
            sum1 = Decimal(sum1) * Decimal(i)
        for j in range(4 * k, 0, -1):                   # /4k! /(396)**(4k)
            sum1 = Decimal(sum1) / Decimal(j) / Decimal(396)
        my_pai += sum1
        k += 1

    my_pai = Decimal(my_pai) * Decimal(2) * Decimal(math.sqrt(2) / 9801)
    my_pai = Decimal(1) / Decimal(my_pai)
    return my_pai


if __name__ == '__main__':

    print('\nk = 100: ')
    print(math.pi)
    start = time.time()
    print(Pai(100))
    print('time_delta:',time.time()-start)

    print('\nk = 500: ')
    print(math.pi)
    start = time.time()
    print(Pai(500))
    print('time_delta:',time.time()-start)
    print(math.pi)

    print('\nk = 1000: ')
    print(math.pi)
    start = time.time()
    print(Pai(1000))
    print('time_delta:',time.time()-start)

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

    '''
    k = 100: 
3.141592653589793
3.141592729880626
time_delta: 0.02562236785888672

k = 500: 
3.141592653589793
3.141592729880626
time_delta: 0.5770566463470459
3.141592653589793

k = 1000: 
3.141592653589793
3.141592729880626
time_delta: 2.1520683765411377

k = 3000: 
3.141592653589793
3.141592729880626
time_delta: 17.46667790412903

k = 5000: 
3.141592653589793
3.141592729880626
time_delta: 49.59669017791748

k = 8000: 
3.141592653589793
3.141592729880626
time_delta: 127.64335894584656'''