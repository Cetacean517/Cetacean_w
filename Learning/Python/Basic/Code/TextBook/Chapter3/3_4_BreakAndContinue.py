"""3.4 引言 计算小于100的最大素数"""


def CountPrime():
    for n in range(100, 1, -1):  # 取从100~2的整数
        for i in range(2, n):
            if n % i == 0:
                break
            else:
                print(n)
                break
    print(2)


def OddNumber():
    """ 输出10以内的奇数"""
    """ 以下代码存在问题：
                i = 2的时候直接执行continue语句，无法执行i+1，从而进入永循环。"""
    # i = 1
    # while i < 10:
    #     if i % 2 == 0:
    #         continue
    #     print(i, end=" ")
    #     i += 1
    """ 修改版 while"""
    i = 0
    while i < 10:
        i += 1
        if i % 2 == 0:
            continue
        print(i, end=" ")
    print("\n")

    """ 修改版 for"""
    for i in range(10):
        if i % 2 == 0:
            continue
        print(i, end=" ")


def LittleDemo():
    """ Python是基于值的内存管理方式。
        每次进入循环时的变量i 已经不再是上一次的变量i，所以修改其值并不会影响循环的执行。"""
    for i in range(5):
        # i = i + 1     # 加上该语句输出的i并不会改变，而id(i)会改变
        print(id(i), ":", i)


if __name__ == '__main__':
    """3.4 引言 计算小于100的最大素数"""
    # CountPrime()
    # OddNumber()
    LittleDemo()  # Python基于值的内存管理方式在循环上的体现
