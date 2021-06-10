from numpy import random
import time
import matplotlib.pyplot as plt
import numpy as np


def Birthday(m, n):
    '''创建m个班级，每个班级n个学生，返回m个班中有存在相同生日数的概率'''
    try:
        while 1:
            count = 0
            if m < 1000 or n < 0:  # 判断输入的m和n是否正确
                print("m or n is not correct.")
                break
            my_class = [[0] * n for _ in range(m)]  # 创建m行n列的二维数组，并且全部初始化为0
            for i in range(m):  # 随机生成生日
                for j in range(n):
                    my_class[i][j] = random.randint(1, 366)

            for i in range(m):  # 利用元组化列表后集合的长度变化，判断是否一个班有同样生日的学生。
                if len(my_class[i]) != len(set(my_class[i])):
                    count += 1
            # print(count / m)
            return count / m
    except ValueError:
        print("The number you enter is not the right type.")


def Birthday1(m, n):
    '''创建m个班级，每个班级n个学生，返回m个班中有存在相同生日数的概率'''
    try:
        count = 0
        my_class = [[0] * n for _ in range(m)]  # 创建m行n列的二维数组，并且全部初始化为0
        for i in range(m):  # 随机生成生日
            for j in range(n):
                my_class[i][j] = random.randint(1, 366)

        for i in range(m):  # 利用元组化列表后集合的长度变化，判断是否一个班有同样生日的学生。
            if len(my_class[i]) != len(set(my_class[i])):
                count += 1
        # print(count / m)
        return count / m
    except ValueError:
        print("The number you enter is not the right type.")


def draw():     # 固定班级人数，改变班级个数
    # 生成数据
    x = [x for x in range(1, 10001, 100)]  # 横坐标数据为从0到10之间，步长为0.1的等差数组
    y = []
    for i in x:
        y.append(Birthday1(i, 30))
    # 生成图形
    plt.plot(x, y)
    # 显示图形
    plt.show()


def draw1():    # 固定班级个数，改变班级人数
    # 生成数据
    x = [x for x in range(1, 100, 1)]  # 横坐标数据为从0到10之间，步长为0.1的等差数组
    y = []
    for i in x:
        y.append(Birthday1(10000, i))
    # 生成图形
    plt.plot(x, y)
    # 显示图形
    plt.show()


if __name__ == '__main__':
    # while 1:
    #     m = input("Please enter the number of the classes(>=1000):")
    #     n = input("Please enter the number of the students of each class:")
    #     m = int(m)
    #     n = int(n)
    #     start = time.time()
    #     Birthday(m,n)
    #     print("Time:", time.time() - start)

    draw1()
