"""3.3.2 循环结构优化"""
from pip._vendor.msgpack.fallback import xrange


def LoopAdvanced1():
    """尽量减少循环内部不必要的计算，将于循环变量无关的计算尽可能的提取到循环之外。
        尤其对于多重循环的情况。"""
    import time
    digits = (1, 2, 3, 4)

    start = time.time()
    for i in range(1000):
        result = []
        for i in digits:
            for j in digits:
                for k in digits:
                    result.append(i * 100 + j * 10 + k)
    print(time.time() - start)
    print(result)

    start = time.time()
    for i in range(1000):
        result = []
        for i in digits:
            i = i * 100
            for j in digits:  # 循环语句中的j并不受循环体中赋值的影响。
                j = j * 10
                for k in digits:
                    result.append(i + j + k)
    print(time.time() - start)
    print(result)


def LoopAdvanced2():
    """在循环中尽量引用局部变量，因为局部变量的查询和访问速度比全局变量略快。
        在使用模块中的方法时，可以通过将其转换为局部变量来提高运行速度。"""
    import time
    import math
    # method 1.1 直接使用
    start = time.time()  # 获取当前时间
    for i in range(10000000):
        math.sin(i)
    print('Time Used:', time.time() - start)  # 输出所用时间

    # method 1.2 利用局部变量转换
    loc_sin = math.sin  # 将模块的某一个方法变成局部变量
    start = time.time()
    """xrange() 函数用法与 range 完全相同，所不同的是生成的不是一个数组，而是一个生成器。"""
    for i in xrange(10000000):
        loc_sin(i)
    print('Time Used:', time.time() - start)  # 输出所用时间

    """利用另一种导入和使用模块成员的方法,只导入所需要的模块也可以提升运行效率"""
    # method 2.1 直接使用
    import time
    from math import sin as sin
    start = time.time()
    for i in range(10000000):
        sin(i)
    print('Time Used:', time.time() - start)  # 输出所用时间

    # method 2.2 利用局部变量转换
    loc_sin = math.sin  # 将模块的某一个方法变成局部变量
    start = time.time()
    for i in range(10000000):
        loc_sin(i)
    print('Time Used:', time.time() - start)  # 输出所用时间


if __name__ == '__main__':
    '''3.3.2 循环结构优化'''
    # LoopAdvanced1()
    # LoopAdvanced2()
