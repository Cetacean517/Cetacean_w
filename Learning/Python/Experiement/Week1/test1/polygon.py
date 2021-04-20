"""This module contains code from
Think Python by Allen B. Downey
http://thinkpython.com

Copyright 2012 Allen B. Downey
License: GNU GPLv3 http://www.gnu.org/licenses/gpl.html

"""

import math

try:
    # see if Swampy is installed as a package
    from swampy.TurtleWorld import *
except ImportError:
    # otherwise see if the modules are on the PYTHONPATH
    from TurtleWorld import *


def square(t, length):
    """Draws a square with sides of the given length.

    Returns the Turtle to the starting position and location.
    """
    for i in range(4):
        fd(t, length)
        lt(t)


def polyline(t, n, length, angle):
    """Draws n line segments.

    t: Turtle object
    n: number of line segments
    length: length of each segment
    angle: degrees between segments
    """
    for i in range(n):      # 画n条边，长度为length，每次向左转angle度
        fd(t, length)
        lt(t, angle)


def polygon(t, n, length):
    """Draws a polygon with n sides.

    t: Turtle
    n: number of sides
    length: length of each side.
    """
    angle = 360.0 / n       # 利用360 /n 限定角度，画一个正n边形
    polyline(t, n, length, angle)


def arc(t, r, angle):
    """Draws an arc with the given radius and angle.

    t: Turtle
    r: radius
    angle: angle subtended by the arc, in degrees
    """
    arc_length = 2 * math.pi * r * abs(angle) / 360  # 计算弧度的长度
    n = int(arc_length / 4) + 1     # 把弧度分成n份，即把画弧转化为画n条边
    step_length = arc_length / n    # 计算步长
    step_angle = float(angle) / n   # 计算每次转过的角度

    # making a slight left turn before starting reduces
    # the error caused by the linear approximation of the arc
    lt(t, step_angle / 2)   # 每次向左转转过角度的一半
    polyline(t, n, step_length, step_angle) # 做折线
    rt(t, step_angle / 2)


def circle(t, r):
    """Draws a circle with the given radius.

    t: Turtle
    r: radius
    """
    arc(t, r, 360)  # 画圆是画弧的特殊情况，直接调用即可


# 创意画：

# 画一片花瓣
def petal(t, r, angle):
    # t: turtle;
    # r: radius;
    # angle: related to the thick of a petal
    for i in range(2):          # 画一个往返的弧线，构成一篇花瓣
        arc(t, r, angle)        # 调用arc依照角度画弧的函数
        lt(t, 180 - angle)      # 向左转向180 -angle = 返回


# 画一朵花
def flower(t, n, r, angle):
    """ t: turtle
    n: 花瓣数
    r: radius
    angle:旋转的角度
    """
    for i in range(n):
        petal(t, r, angle)
        lt(t, 360.0 / n)    # n 片花瓣旋转一周，偏转角度为360/n


def move(t, length):        # 利用pu(),pd() 不转向移动turtle的位置
    pu(t)
    fd(t, length)
    pd(t)


def back(t, r, angle):
    pu(t)
    arc_length = 2 * math.pi * r * abs(angle) / 360
    n = int(arc_length / 4) + 1
    step_length = arc_length / n
    step_angle = float(angle) / n
    fd(t, step_length)
    pd(t)


#
# the following condition checks whether we are running as a script, in which case run the test code,
# or being imported, in which case don't.

if __name__ == '__main__':
    # 创建世界和乌龟，并加速bob运动的速度
    world = TurtleWorld()
    bob = Turtle()
    bob.delay = 0.001           # 设置乌龟走过路程间隔的速度（提速）
    # 第一朵六片花
    flower(bob, 6, 96, 57)

    # 第二朵花
    move(bob, 200)              # 移动一段位置，避免和第一朵花重叠
    flower(bob, 10, 90, 80)     # 画第二朵花
    rt(bob, 90)                 # 转向，画花茎
    fd(bob, 300)
    lt(bob, 90)                 # 转向，画第一片叶子
    petal(bob, 100, 80)
    lt(bob, 90)                 # 转向，画第二片叶子
    petal(bob, 100, 80)

    wait_for_user()
