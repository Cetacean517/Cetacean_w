""" 12. 编写函数，模拟内置函数sorted。"""


def my_sorted(iterable):
    from collections.abc import Iterable
    if not isinstance(iterable, Iterable):
        print('TypeError: only receive iterable')
        return
    u = []
    temp = [x for x in iterable]  # 复制原列表
    while temp:
        Min = min(temp)
        u.append(Min)
        temp.remove(Min)
    return u


if __name__ == '__main__':
    # l = [2, 3, 1, 4]
    l = (2, 3, 1, 4)
    # [1, 2, 3, 4]
    print(my_sorted(l))
    l1 = ['a', 'd', 'b', 'z', 'q']
    print(my_sorted(l1))
    # ['a', 'b', 'd', 'q', 'z']
