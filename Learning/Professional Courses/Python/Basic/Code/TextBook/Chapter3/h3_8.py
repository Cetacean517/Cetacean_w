"""8. 编写程序，输出所有由1、2、3、4这四个数字组成的素数，并且在每个素数中每个数字只使用一次。"""


def isPrime(n):
    """ 判断一个数是否为素数
        本例主要演示循环结构中else子句的用法"""
    import math

    m = math.ceil(math.sqrt(n) + 1)  # 取n开根号的值，+1是因为range是闭开区间
    for i in range(2, m):
        if n % i == 0 and i < n:
            return False
    else:
        return True


def findPrime():
    """ 利用循环求和，得到1,2,3,4的全排列序列"""
    digits = (1, 2, 3, 4)
    all = []
    for i in digits:
        for j in digits:
            if i == j:
                continue
            for k in digits:
                if i == k or j == k:
                    continue
                for m in digits:
                    if i == m or j == m or k == m:
                        continue
                    all.append(i * 1000 + j * 100 + k * 10 + m)
    prime = [i for i in all if isPrime(i)]
    print(prime)
    return


def findPrime2():
    """利用字符串拼接 和列表生成式，得到1,2,3,4的全排序序列"""
    digits = ['1', '2', '3', '4']
    all = [x + y + z + m for x in digits for y in digits for z in digits for m in digits \
           if x != y and x != z and x != m and y != z and y != m and z != m]
    prime = [int(i) for i in all if isPrime(int(i))]
    print(prime)
    return


findPrime()
findPrime2()
