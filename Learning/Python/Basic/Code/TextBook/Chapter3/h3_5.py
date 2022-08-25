"""5. 编写程序，生成一个包含20个随机整数的列表，然后对其中偶数下标的元素进行降序排列，奇数下标的元素不变。（提示：使用切片）"""
import random


def sort_odd():
    a = [random.randint(0, 10) for i in range(20)]  # 构造随机列表
    print('origin:', a)
    b = a[1::2]  # 取a中偶数位的数字，生成列表
    b = sorted(b, reverse=True)  # 降序排序
    i = 1   # 循环标记
    j = 0   # 循环标记
    while i < len(a):   # 进行列表成员替换
        a[i] = b[j]
        i += 2
        j += 1
    print('sorted:', a)
    print('even list:', b)


sort_odd()
