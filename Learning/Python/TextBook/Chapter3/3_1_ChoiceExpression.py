"""Python中，if条件表达式的值只要不是False,0,空
    都可以认为与True等价"""


def if_while_test():
    if 3:
        print(5)
    a = [1, 2, 3]

    if a:
        print(6)
    b = []

    if b:
        print(b)
    else:
        print('empty')

    i = s = 0
    # 1~10求和
    while True:
        s += i
        i += 1
        if i > 10:
            break
    print(s)
    # 1~10求和，range范围：[0,11),步长为1
    s = 0
    for i in range(0, 11, 1):
        s += i
    print(s)


def several_compare():
    print(1 < 2 < 3)
    print(1 < 2 > 3)
    print(1 < 3 > 2)


def short_route():
    """逻辑运算符 and 和 or 可以利用短路求值和惰性求值的特点（只计算必须计算的表达式的值），来提高运行效率。
       例：and 运算，只要出现一个0，则值为0，之后其他内容不用计算。
           or 运算，只要出现一,1，则值为1，之后其他内容不用计算。"""
    '''功能：使用用户指定的分隔符将多个字符串连接成一个字符串，如果用户没有指定，则默认使用','。
        join()函数
        
        语法：  'sep'.join(seq)
        
        参数说明:
        sep：分隔符。可以为空
        seq：要连接的元素序列、字符串、元组、字典
        上面的语法即：以sep作为分隔符，将seq所有的元素合并成一个新的字符串

        返回值：返回一个以分隔符sep连接各个元素后生成的字符串'''
    # 定义1.0
    def Join(chList, sep=None):
        return (sep or ',').join(chList)

    # 定义2.0，利用默认参数
    def Join(chList, sep=','):
        return sep.join(chList)
    chTest = ['1', '2', '3', '4', '5']
    print(Join(chTest))
    print(Join(chTest, ':'))

# if条件判断不能使用=
# if a = 3: 会报错

if __name__ == "__main__":
    # '''if循环测试'''
    # if_while_test()
    # '''关系运算符的连续使用'''
    # several_compare()
    '''短路运算测试'''
    short_route()
