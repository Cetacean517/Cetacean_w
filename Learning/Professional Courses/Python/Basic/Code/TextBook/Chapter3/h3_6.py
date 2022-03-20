"""6. 编写程序，用户从键盘输入小于1000的整数，对其进行因式分解。例如，10 = 2*5, 60 = 2*2*3*5。"""


def getPrime():
    """利用filter()过滤和生成器，输出素数列表"""

    def _odd_iter():
        n = 1
        while True:
            n = n + 2
            yield n

    def _not_divisible(n):
        return lambda x: x % n > 0

    def primes():
        yield 2
        it = _odd_iter()  # 初始化序列
        while True:
            n = next(it)
            yield n
            it = filter(_not_divisible(n), it)  # 构造新序列

    a = []
    for n in primes():
        if n < 1000:
            a.append(n)
        else:
            break
    return a


def factorization(x):
    print(x, ' =', end=' ')
    p = getPrime()

    if x in p:      # 如果x时素数，则直接输出x
        print(x)
        return

    for i in p:     # 如果x可以被因式分解，则进入循环
        if x == 1:  # 因式分解完成，跳出循环
            break
        while x % i == 0:   # 寻找x的因子
            if x in p:      # 找到x的最后一个因子，输出该因子，并给x赋值为1
                print(x)
                x = 1
            else:
                print(i, ' * ', end=' ')
                x = x // i


x = input('请输入一个小于1000的正整数: ')
factorization(int(x))