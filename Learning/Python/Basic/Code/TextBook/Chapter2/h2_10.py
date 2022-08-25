"""10. 编写程序，生成包含20个随机数的列表，然后将前10个元素升序排列，后10个元素降序排列，并输出结果。"""


def sort_my():
    import random
    a = [random.randint(0, 10) for i in range(20)]  # 创建包含20个0-9的随机数列表
    print(sorted(a[:10], reverse=False) + sorted(a[:-10], reverse=True))    # 利用切片和sorted()函数实现排序


sort_my()
