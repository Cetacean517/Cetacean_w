# 科赫雪花
import turtle


def kehe(len, n):
    if n == 0:
        turtle.fd(len)  # 0阶时，走直线，长度为len
    else:
        for i in [0, 60, -120, 60]:  # 依次向左转指定角度调用n-1阶的kehe函数
            turtle.left(i)
            kehe(len / 3, n - 1)


def Koch(level):
    turtle.speed(0)  # 设置乌龟的速度
    turtle.penup()  # 拿起画笔
    turtle.goto(-200, 100)  # 设置初始点（-100，100）
    turtle.pensize(2)  # 设置笔的粗细
    turtle.color('blue')  # 设置笔的颜色为蓝色
    turtle.pendown()  # 放下画笔

    for i in range(3):
        kehe(lenth, level)  # 转向画3次
        turtle.right(du)

    turtle.hideturtle()  # 隐藏乌龟（即箭头）
    turtle.done()


if __name__ == '__main__':
    lenth = 500
    du = 120
    level = (input('please enter a number:'))
    level = int(level)
    Koch(level)
