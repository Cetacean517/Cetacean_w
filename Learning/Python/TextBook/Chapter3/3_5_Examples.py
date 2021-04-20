# 例3-4 内置函数的使用（代码行数简单）
def CountOneHundred():
    """计算1+2+3+4+...100的值"""
    s = 0
    for i in range(1, 101):
        s += i
    print("1+2+3+4+...100=", s)
    print("1+2+3+4+...100=", sum(range(1, 101)))  # 直接使用内置函数来实现题目的要求


# 例3-5 enumerate() 函数
def PrintList():
    """ 例 3-5 输出序列中的元素
               对于类似元素遍历的问题，一般优先考虑 for循环"""
    # 利用 for 解决
    a_list = ['a', 'b', 'mpilgrim', 'z', 'example']
    for i, v in enumerate(a_list):
        print('列表的第', i + 1, '个元素是：', v)
    ''' enumerate() 
        函数用于将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，同时列出数据和数据下标，一般用在 for 循环当中。
        Python 2.3. 以上版本可用，2.6 添加 start 参数。

        语法 
        enumerate(sequence, [start=0])

        参数
        sequence -- 一个序列、迭代器或其他支持迭代对象。
        start -- 下标起始位置。

        返回值
        返回 enumerate(枚举) 对象。'''
    print('\n')
    # 利用while解决
    a_list = ['a', 'b', 'mpilgrim', 'z', 'example']
    i = 0
    number = len(a_list)
    while i < number:
        print('列表的第', i + 1, '个元素是：', a_list[i])
        i += 1


# 例3-6
def Divided():
    """ 求1~100之间内被7整除，但不能同时被5整除的所有整数。"""
    for i in range(1, 101):
        if i % 7 == 0 and i % 5 != 0:
            print(i)


# 例3-7
def NarcissisticNumber():
    """ 输出’水仙花数‘。所谓水仙花数是指1个3位十进制数，其各位数字的立方和恰好等于该数本身。
        例如，153是水仙花数。 因为 153 = 1*1*1 + 5*5*5 + 3*3*3"""
    print("水仙花数：")
    for i in range(100, 1000):
        ge = i % 10
        shi = i // 10 % 10
        bai = i // 100
        if ge ** 3 + bai ** 3 + shi ** 3 == i:
            print(i, end=" ")


# 例3-8
def GetAverage():
    """ 求平均分"""
    score = [70, 90, 78, 85, 97, 94, 65, 80]
    s = 0
    for i in score:
        s += i
    print(s / len(score))
    print("使用内置函数输出结果：", s / len(score))


# 例3-9
def PrintMultipleTable():
    """ 打印九九乘法表"""
    for i in range(1, 10):
        for j in range(1, i + 1):
            print(i, '*', j, '=', i * j, '\t', end='')
        print()  # 打印空行


# 例3-10
def MaxInteger():
    """ 求200以内能被17整除的最大正整数 """
    for i in range(200, 0, -1):  # 倒序求最大值
        if i % 17 == 0:
            print(i)
            break


# 例3-11 特殊的else语句
def JudgePrime():
    """ 判断一个数是否为素数
        本例主要演示循环结构中else子句的用法"""
    import math

    n = input('Input an integer:')
    n = int(n)
    m = math.ceil(math.sqrt(n) + 1)  # 取n开根号的值，+1是因为range是闭开区间
    for i in range(2, m):
        if n % i == 0 and i < n:
            print('No')
            break
    else:
        print('Yes')


# 例3-12
def ChickWithRabbit():
    """ 鸡兔同笼问题。
        假设共有鸡、兔30只，脚90只，求鸡、兔各有多少只。"""
    for ji in range(0, 31):
        if 2 * ji + (30 - ji) * 4 == 90:
            print('ji:', ji, 'tu:', 30 - ji)


# 例3-13 循环优化：continue
def GetMixNumber():
    """ 编写程序，输出由 1、2、3、4这4个数字组成的每位数都不相同的所有三位数。"""
    # 1.0 运行效率不是很好
    print(" world 1.0")
    digits = (1, 2, 3, 4)
    for i in digits:
        for j in digits:
            for k in digits:
                if i != j and j != k and i != k:
                    print(i * 100 + j * 10 + k, end=' ')
    # 2.0 将一些运算提到循环外
    print('\n', 'world 2.0')
    digits = (1, 2, 3, 4)
    for i in digits:
        for j in digits:
            if i == j:
                continue
            for k in digits:
                if i == k or j == k:
                    continue
                print(i * 100 + j * 10 + k, end=' ')


# 例3-14 random库和randint的使用
def RandomTwenty():
    """ 编写程序，生成一个含有20个随机数的列表，要求所有元素不相同，并且每个元素的值介于1~100之间。"""
    import random

    x = []
    while True:
        if len(x) == 20:
            break
        else:
            n = random.randint(1, 100)
            if n not in x:
                x.append(n)
    print(x)


# 例3-15
def CombinatorialNumber(n, i):
    """ 编写程序，计算组合数 C(n,i), 即从n个元素中任选i个，有多少种选法。
        以 Cni(8,3) 为例，按定义式展开为  Cni(8,3) = 8!/3!/(8-3)! = (8*7*6*5*4*3*2*1)/(3*2*1)/(5*4*3*2*1),
        对于 (5,8]区间的数，分子上出现一次而分母上没有出现；
            (3,5]区间的数，在分子和分母上各出现一次；
            [1,3]区间的数，在分子上出现一次，分母上出现两次
    """

    def Cni1(n, i):
        if not (isinstance(n, int) and isinstance(i, int) and n >= i):
            print('n and i must be integers and n must be larger than or equal to i.')
        result = 1
        Min, Max = min(i, n - i), max(i, n - i)  # 对于(8,3) 取判断标志：8 和 8-3 = 5
        for i in range(n, 0, -1):  # 对于1~8中的数字 做* 或者÷ 运算
            if i > Max:  # 比5大的做乘法（参考注释中原理）
                result *= i
            elif i <= Min:  # 比4小的做除法
                result /= i
        return result

    def Cni2(n, i):
        import math
        return int(math.factorial(n) / math.factorial(i) / math.factorial(n - i))

    def Cni3(n, i):
        import itertools
        print(len(tuple(itertools.combinations(range(n), i))))

    import time
    start = time.time()
    print('method1:', Cni1(n, i))
    print(time.time() - start)

    start = time.time()
    print('method2:', Cni2(n, i))
    print(time.time() - start)

    start = time.time()
    print('method3: ', end='')
    Cni3(n, i)
    print(time.time() - start)
    ''' 方法1是 效率最高，且可计算数据最大的方法，方法2次之；方法3最差。'''


# itertools库
def IterTools():
    import itertools
    x = 'Private Key'
    '''cycle()函数：循环遍历可迭代对象的函数'''
    y = itertools.cycle(x)  # 循环遍历序列中的元素
    for i in range(20):
        print(next(y), end=',')  # P,r,i,v,a,t,e, ,K,e,y,P,r,i,v,a,t,e, ,K,

    print()
    for i in range(5):
        print(next(y), end=',')  # e,y,P,r,i,

    ''' compress(): 根据一个序列的值对另一个序列进行过滤。'''
    print()
    x = range(1, 20)
    y = (1, 0) * 9 + (1,)
    print(y)  # (1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1)
    print(list(itertools.compress(x, y)))  # 根据一个序列的值对另一个序列进行过滤

    '''groupby(): 根据函数返回值对序列进行分组。'''

    def group(v):
        if v > 10:
            return 'greater than 10'
        elif v < 5:
            return 'less than 5'
        else:
            return 'between 5 and 10'

    x = range(20)
    y = itertools.groupby(x, group)  # 根据函数返回值对序列元素进行分组
    for k, v in y:
        print(k, ':', list(v))

    ''' permutations(): 从列表中指定元素个数进行排列'''
    print(list(itertools.permutations([1, 2, 3, 4], 3)))  # 从4个元素中任选3个的所有排列

    x = itertools.permutations([1, 2, 3, 4], 4)
    print(next(x))  # (1, 2, 3, 4)
    print(next(x))  # (1, 2, 4, 3)
    print(next(x))  # (1, 3, 2, 4)


# 例3-16
def SumLiCai():
    """ 编写程序，计算理财产品收益。
        理财产品比定期存款的周期短，利息和本金一起滚动，不同于定期存款收益的计算方法。"""

    def licai(base, rate, days):
        # 初始投资金额
        result = base
        # 整除，用来计算一年可以滚动多少期
        times = 365 // days
        for i in range(times):
            result = result + result * rate / 365 * days
        return result

    print(licai(10000, 0.0385, 14))


if __name__ == '__main__':
    """ 例 3-4 计算1+2+3+4+...100的值"""
    # CountOneHundred()
    """ 例 3-5 输出序列中的元素"""
    # PrintList()
    """ 例 3-6 求1~100之间内被7整除，但不能同时被5整除的所有整数。"""
    # Divided()
    """ 例 3-7 输出'水仙花数'。"""
    # NarcissisticNumber()
    """ 例 3-8 求平均分。"""
    # GetAverage()
    """ 例 3-9 打印九九乘法表。"""
    # PrintMultipleTable()
    """ 例 3-10 求200以内能被17整除的最大正整数。"""
    # MaxInteger()
    """ 例 3-11 判断一个数是否为素数。"""
    # JudgePrime()
    """ 例 3-12 鸡兔同笼问题。"""
    # ChickWithRabbit()
    """ 例 3-13 输出由1,2,3,4所有数字不相同的三位数。"""
    # GetMixNumber()
    """ 例 3-14 编写程序，生成一个含有20个随机数的列表，要求所有元素不相同，并且每个元素的值介于1~100之间。"""
    # RandomTwenty()
    """ 例 3-15 编写程序，计算组合数 C(n,i), 即从n个元素中任选i个，有多少种选法。"""
    # CombinatorialNumber(300,5)
    # IterTools()
    """ 例 3-16 编写程序，计算理财产品收益。"""
    SumLiCai()
