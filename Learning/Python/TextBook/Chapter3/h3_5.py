'''5. 编写程序，生成一个包含20个随机整数的列表，然后对其中偶数下标的元素进行降序排列，奇数下标的元素不变。（提示：使用切片）'''
import random


def sort_odd():
    a = [random.randint(0, 10) for i in range(20)]
    print(a)
    b = a[::-2]
    b = sorted(b, reverse=True)
    print(b)
    i = 1;j = 0
    if i <= len(a):
        a[i] = b[j]
        i += 2
        j += 1
    print(a)


sort_odd()
