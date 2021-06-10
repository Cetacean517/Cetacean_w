"""编写程序，生成一个包含50个随机整数的列表，然后删除其中所有奇数（提示：从后向前删）。"""
import random


def deleteOdd():
    a = [random.randint(0, 10) for i in range(50)]
    print(a)
    for i in a[::-1]:
        if i % 2 == 1:
            a.remove(i)
    print(a)


deleteOdd()
