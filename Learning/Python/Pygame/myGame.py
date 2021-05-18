# pygame最小运行框架
import pygame
import sys
import random
import time


# 把场景视为一个二维网格（数组），进行网格构建
class Vex():
    row = 0
    col = 0

    def __init__(self, row, col):
        self.row = row
        self.col = col

    def copy(self):
        return Vex(row=self.row, col=self.col)


# 初始化游戏
pygame.init()
# 设置游戏图标
icon = pygame.image.load("ggirl.jpg")
pygame.display.set_icon(icon)
# 设置游戏可调节页面
'''在循环之前感知屏幕的大小，并把它赋值给当前的游戏。'''
vInfo = pygame.display.Info()
size = width, height = 700, 400
screen = pygame.display.set_mode(size, pygame.RESIZABLE)
# 设计游戏标题
pygame.display.set_caption("贪吃蛇小游戏")
fps = 10
fclock = pygame.time.Clock()
# 初始化数据
ROW = 30
COL = 40
direct = 'left'
# 设置蛇头位置再中间
snake_head = Vex(row=int(ROW / 2), col=int(COL / 2))
# 初始化蛇身体的元素数量
snake = [
    Vex(row=snake_head.row, col=snake_head.col + 1),
    Vex(row=snake_head.row, col=snake_head.col + 2),
    Vex(row=snake_head.row, col=snake_head.col + 3)
]


# 随机生成食物,且食物不能生成再蛇的身体内部
def get_food():
    while 1:
        position = Vex(row=random.randint(0, ROW - 1), col=random.randint(0, COL - 1))
        inBody = False
        # 如果生成的食物在蛇的身体里面，则重新生成
        if snake_head.row == position.row and snake_head.col == position.col:
            inBody = True
        for body in snake:
            if body.row == position.row and body.col == position.col:
                inBody = True
                break
                # 直到生成没有在蛇身体内的食物返回食物位置
        if not inBody:
            break
    return position


# 定义坐标
# 定义蛇头的颜色
h_color = (155, 150, 238)
# 食物的坐标
s_food = get_food()
# 食物的颜色
snake_food_color = (255, 255, 0)
snake_color = pygame.Color("white")


# 需要执行很多步画图操作 所以定义一个函数
def rect(point, color):
    # 定位 画图需要left和top
    left = point.col * width / COL
    top = point.row * height / ROW
    # 将方块涂色
    pygame.draw.rect(screen, color, (left, top, width / COL, height / ROW))

def RGBChannel(a):
    return 0 if a < 0 else (255 if a > 255 else int(a))

# 设置出口判断变量
quit = True
while quit:
    now = time.ctime()
    clock = now[11:19]
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            # 贪吃蛇不能够直接左右上下，要判断当前是在什么状态下前行
            if event.key == pygame.K_UP or event.key == 119:
                if direct == 'left' or direct == 'right':
                    direct = 'top'
            if event.key == pygame.K_DOWN or event.key == 115:
                if direct == 'left' or direct == 'right':
                    direct = 'bottom'
            if event.key == pygame.K_LEFT or event.key == 97:
                if direct == 'top' or direct == 'bottom':
                    direct = 'left'
            if event.key == pygame.K_RIGHT or event.key == 100:
                if direct == 'top' or direct == 'bottom':
                    direct = 'right'
    # 吃果子
    eat = (snake_head.row == s_food.row and snake_head.col == s_food.col)

    # 对吃了果子的蛇身进行修改
    if eat:
        # 随机产生果子
        s_food = Vex(row=random.randint(0, ROW - 1), col=random.randint(0, COL - 1))
    snake.insert(0, snake_head.copy())
    if not eat:
        snake.pop()

    if direct == 'left':
        snake_head.col -= 1
    if direct == 'right':
        snake_head.col += 1
    if direct == 'top':
        snake_head.row -= 1
    if direct == 'bottom':
        snake_head.row += 1
    dead = False
    if snake_head.col < 0 or snake_head.row < 0 or snake_head.col >= COL or snake_head.row >= ROW:
        dead = True
    for body in snake:
        if snake_head.col == body.col and snake_head == body.row:
            dead = True
            break
    if dead:
        print("GAME OVER")
        quit = False

    pygame.draw.rect(screen, (150, 200, 220), (0, 0, width, height))
    snake_color.r = RGBChannel(snake_head.col * 255 / COL)
    snake_color.g = RGBChannel(snake_head.row * 255 / ROW)
    snake_color.b = RGBChannel(random.randint(0, 255))
    # 绘制蛇和食物
    rect(snake_head, h_color)
    for body in snake:
        rect(body, snake_color)
    rect(s_food, snake_food_color)
    fclock.tick(fps)
    pygame.display.flip()
