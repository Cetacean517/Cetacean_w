import timeit
import random

from urllib3.connectionpool import xrange


def format0():
    pi = 3.1416926
    month = 1
    print('%3s' % month)
    # 输出2位小数
    print('%.3f' % pi)


def format():
    print("The number {0:,} in hex is : {0:#x}, the number {1} in oct is {1:#o}".format(5555, 55))
    # The number 5,555 in hex is : 0x15b3, the number 55 in oct is 0o67
    print("The number {1:,} in hex is : {1:#x}, the number {0} in oct is {0:#o}".format(5555, 55))
    # The number 55 in hex is : 0x37, the number 5555 in oct is 0o12663
    # 把元组中的元素作为列表中的一项，二维调用
    positon = (5, 8, 13)
    print("X:{0[0]};Y:{0[1]};Z:{0[2]}".format(positon))


#     X:5;Y:8;Z:13


strlist = ['This is a long string that will not keep in memory.' for n in xrange(100)]


def use_join():
    return ''.join(strlist)


def use_plus():
    result = ''
    for strtemp in strlist:
        result = result + strtemp
    return result

def hongbao(total,num):
    each=[]
    already = 0
    for i in range(1,num):
        t = random.randint(1,total - already-(num-i))       # num-i 保证每次剩余的每个人至少有1元
        print(t)
        each.append(t)
        already = already + t
    each.append(total-already)
    return each

if __name__ == '__main__':
    ''' 测试join 和 plus 的运行速度 join更快'''
    # # format()
    # times = 1000
    # jointimer = timeit.Timer('use_join()', 'from __main__ import use_join')
    # print('time for join:', jointimer.timeit(number=times))
    # plustimer = timeit.Timer('use_plus()', 'from __main__ import use_plus')
    # print('time for plus：', plustimer.timeit(number=times))
    ''' 模拟发红包算法 '''
    # 总金额5元 每次5个 30次
    total = 30
    num = 5
    for i in range(30):
        each = hongbao(total,num)
        print(each)
