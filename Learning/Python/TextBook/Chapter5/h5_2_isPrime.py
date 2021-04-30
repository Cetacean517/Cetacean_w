"""2. 编写函数，判断一个整数是否为素数。并编写主程序调用该函数。"""


def isPrime():
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


if __name__ == '__main__':
    isPrime()
