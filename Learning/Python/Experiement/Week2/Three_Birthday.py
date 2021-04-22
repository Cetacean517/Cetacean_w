from numpy import random
import time


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

            for i in range(m):   # 利用元组化列表后集合的长度变化，判断是否一个班有同样生日的学生。
                if len(my_class[i]) != len(set(my_class[i])):
                    count += 1
            print(count / m)
            break;
    except ValueError:
        print("The number you enter is not the right type.")



if __name__ == '__main__':
    while 1:
        m = input("Please enter the number of the classes(>=1000):")
        n = input("Please enter the number of the students of each class:")
        m = int(m)
        n = int(n)
        start = time.time()
        Birthday(m,n)
        print("Time:", time.time() - start)
