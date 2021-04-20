# 样例数组中不含有连续的1
def remove_1():
    x = [1, 2, 1, 2, 1, 2, 1, 2, 1]
    for i in x:
        if i == 1:
            x.remove(i)
    print(x)


# 样例数组中含有连续的1
def remove_2():
    x = [1, 2, 1, 1, 1, 2, 1, 1]
    for i in x:
        if i == 1:
            x.remove(i)
    print(x)


# 修正，利用切片
def remove_c():
    x = [1, 2, 1, 1, 1, 2, 1, 1]
    for i in x[::]:
        if i == 1:
            x.remove(i)
    print(x)


if __name__ == "__main__":
    remove_1()
    # [2, 2, 2, 2]
    remove_2()
#     [2, 2, 1, 1]
    remove_c()
'''1删除不干净的原因是：Python会自动对列表内存进行收缩并移动列表元素，以保证所以元素之间没有空隙。
增加列表元素的时候也会移动。
    当读到一个数组中有连续的1的时候，删除前一个1后，下一个1会收缩，向前移。导致下一个1没有被判断到。'''
