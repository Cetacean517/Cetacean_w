"""9. 编写程序，实现分段函数计算，如表3-1所示。"""


def piecewiseFuction(x):
    if x < 0:
        print(0)
        return 0
    elif 0 <= x < 5:
        print(x)
        return x
    elif 5 <= x < 10:
        print(3 * x - 5)
        return 3 * x - 5
    elif 10 <= x < 20:
        print(0.5 * x - 2)
        return 0.5 * x - 2
    elif 20 <= x:
        print(0)
        return 0

x = input('x:')
piecewiseFuction(int(x))