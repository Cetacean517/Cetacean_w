from swampy.TurtleWorld import *
import math

world = TurtleWorld()  # 创建世界


# 初学样例
# world = TurtleWorld()
# bob = Turtle()
# print(bob)

# for i in range(4):
#     fd(bob, 100)
#     lt(bob)


#  写一个函数square ，接受一个形参 t，用来表示一只乌龟,接受length,表示步长。用来表示一只乌龟利用乌龟来画一个正方形。
#  写一个函数调用传入bob作为实参来调,用 square函数，并再运行一遍程序。
def square(t, length):
    t = Turtle()
    for i in range(4):
        fd(t, length)  # 参数2：步长
        lt(t)  # 参数2：angle 旋转角度，默认为90°


# 画一个n边形
def multi_square(t, length, n):
    # ''' 参数1：turtle, 参数2：步长, 参数3：边数
    t = Turtle()
    for i in range(n):
        fd(t, length)
        lt(t, 360 / n)


#  画一个圆
#  写一个函数 circle接受代表乌龟的形参 t，以及表示半径的形参 r，并使用合适的长度和边数调用 polygon画一个近似的圆。
#  使用不同的r值来测试你的函数。
#  提示：思考圆的周长（circumference），并保证 length * n = circumference。
#  另一个提示：如果你感觉bob太慢了，可以修改bob.delay来加速。bob.delay代表每次行动之间的停顿，单位是秒。
#  bob.delay代表每次行动之间的停顿，单位是秒。 bob. delay = 0.01应该能让他跑得足够快。
def lines(t, n, length, angle):
    for i in range(n):
        fd(t, length)
        lt(t, angle)


def circle(t, r):
    t = Turtle()
    t.delay = 0.01
    circum = 2 * math.pi * r
    n = int(circum / 4) + 1  # 对周长/4取整加1
    length = circum / n  # 把周长分成n份
    angle = 360.0 / n  # 把角度分成n
    lt(t, angle / 2)
    lines(t, n, length, angle)
    rt(t, angle / 2)


if __name__ == "__main__":
    # multi_square('bob', 100, 5)
    circle('bob', 90)

wait_for_user()  # 不关闭程序等待用户，类似system("Pause")??
