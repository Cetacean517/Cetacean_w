'''模拟sum:
描述
sum() 方法对序列进行求和计算。

语法
以下是 sum() 方法的语法:

sum(iterable[, start])
参数
iterable -- 可迭代对象，如：列表、元组、集合。
start -- 指定相加的参数，如果没有设置这个值，默认为0。'''


def my_Sum(p, a=0):
    try:
        from collections.abc import Iterator
        s = 0
        if a != 0 and isinstance(a,int):
            s += a
        elif not isinstance(a,int):
            print('add data type error.')
            return
        if isinstance(iter(p), Iterator):  # 判断传入的参数是一个迭代器类型的参数
            for i in p:
                if isinstance(i, int):     # 判断传入的迭代器中的每个成员都是int类型
                    s += i
                else:
                    print('list member type error.')    # 对于非int类型成员，进行异常处理
                    return
            print(s)
        return
    except TypeError:
        print('TypeError： object is not iterable.') # 对于非迭代器成员进行异常处理


if __name__ == '__main__':
    l = [1, 2, 3, 4]
    li = (1, 2, 3, 4)
    # 对列表求和测试
    my_Sum(l)
    my_Sum(l, -5)
    # 对元组求和测试
    my_Sum(li)
    # 对range迭代器求和测试
    my_Sum(range(0, 6))
    # 对类型异常进行测试
    my_Sum(0)
    my_Sum([1,2,'a'])
    my_Sum([1,2,3],'a')

