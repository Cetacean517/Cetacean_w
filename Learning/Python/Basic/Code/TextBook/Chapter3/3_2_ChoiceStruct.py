from pip._vendor.distlib.compat import raw_input


def single_if():
    x = input('Input two numbers:')
    a, b = map(int, x.split())
    if a > b:
        a, b = b, a
    print(a, b)


def if_else():
    chTest = ['1', '2', '3', '4', '5']
    if chTest:
        print(chTest)
    else:
        print('empty')


def v1_if_else_v2():
    """ value1 if condition else value2
        condition的值与True等价时，表达式的值位value1;否则，值为value2
    """
    a = 5
    print(6) if a > 5 else print(5)
    print(6 if a > 3 else 5)
    b = 6 if a > 13 else 9
    print(b)

    # 测试if的惰性，此时没有引入random库，但是由于5 > 3 == True，所以可以输出结果为3.0
    import math
    x = math.sqrt(9) if 5 > 3 else random.randint(1, 100)
    print(x)
    # 测试if的惰性，此时必须引入random库，因为2 > 3 == False，所以需要调用random输出结果
    import random
    x = math.sqrt(9) if 2 > 3 else random.randint(1, 100)
    print(x)


def interview():
    age = 24
    subject = "计算机"
    college = "非重点"
    if (age > 25 and subject == "电子信息工程") or (college == '重点' and subject == "电子信息工程") or (
            age <= 28 and subject == "计算机"):
        print('Congratulations!')
    else:
        print('I am sorry.')


def score_input():
    '''用户输入若干个成绩，求所有成绩的总和。每输入一个成绩后询问是否继续输入下一个成绩，回答yes就继续输入下一个成绩，回答no停止输入成绩'''
    '''
    eval()函数
    描述
    eval() 函数用来执行一个字符串表达式，并返回表达式的值。

    语法
    以下是 eval() 方法的语法:

    eval(expression[, globals[, locals]])
    参数
    expression -- 表达式。
    globals -- 变量作用域，全局命名空间，如果被提供，则必须是一个字典对象。
    locals -- 变量作用域，局部命名空间，如果被提供，可以是任何映射对象。
    返回值
    返回表达式计算结果。
    
    raw_input() 和input的区别？？？
'''
    endFlag = 'yes'
    s = 0
    while endFlag.lower() == 'yes':
        x = input('请输入一个正整数：')
        x = eval(x)
        if isinstance(x, int) and 0 <= x <= 100:
            s = s + x
        else:
            print('不是数字或者不符合要求')
        endFlag = raw_input('继续输入？(yes or no)')
        print("整数之和", s)


def CountDay(year, month, day):
    import time

    def demo(year, month, day):
        """编写程序，判断某天是某年第几天。
            本例要点是闰年判断时条件表达式的写法以及关系运算符、逻辑运算符和切片的运用。"""
        day_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]  # 每月的天数
        if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):  # 判断是否为闰年
            day_month[1] = 29  # 闰年2月为29天
        if month == 1:
            return day
        else:
            return sum(day_month[:month - 1]) + day

    date = time.localtime()  # time.localtime()返回的是一个对象<class 'time.struct_time'>
    year, month, day = date[:3]  # date[:3]切片后返回的整体是一个元组，tuple;
    # 可以利用元组给"="左侧的变量赋值，赋值类型和元组中元素类型一致
    print(demo(year, month, day))
    '''date标准库提供了timedelta对象可以很方便的计算指定年，月，日，时，分，秒之前或者之后的日期时间，
        还提供了返回结果包含“今天是今年第几天”，“今天是本周第几天”等答案的timetuple()函数等等'''


def LearningTime():
    import datetime
    Today = datetime.date.today()  # 返回今天的日期 ：年-月—日
    print(Today)
    ''' 原理： 今天日期 - 今年1月1日 + 一天'''
    delta = Today - datetime.date(Today.year, 1, 1) + datetime.timedelta(days=1)  # 今天是今年的第几天
    print(delta)
    test1 = Today.timetuple().tm_yday  # 今天是今年的第几天
    print("输出今天是今年的第几天：", test1)
    test2 = Today.replace(year=2013)  # 替换日期中的年
    print("替换日期中的年：", test2)
    test3 = Today.replace(month=1)  # 替换日期中的月
    print("替换日期中的月：", test3)
    now = datetime.datetime.now()
    print("输出替换后的时间：", now)
    test4 = now.replace(second=30)  # 替换日期中的秒
    print("替换日期中的秒：", test4)
    test5 = now + datetime.timedelta(days=5)    # 计算5天后的日期时间
    print("计算5天后的日期时间", test5)
    test6 = now + datetime.timedelta(weeks=-5)    # 计算5周前的日期时间
    print("计算5周前的日期时间", test6)


if __name__ == '__main__':
    # ''' 3.2.1 单分支选择结构'''
    # single_if()
    # ''' 3.2.2 双分支选择结构'''
    # if_else()
    # '''单行的if表达式'''
    # v1_if_else_v2()
    # '''略 3.2.3多分支选择结构
    #    略 3.2.4选择结构嵌套'''
    ''' 3.2.5 应用案例'''
    # 3-1 面试资格确认
    # interview()
    # 3-2 用户输入成绩
    # score_input()
    # 3—3 某天是某年的第几天
    # CountDay(2021, 4, 18)
    # #学习datetime库函数
    # LearningTime()
