import pygame
import sys

pygame.init()
icon = pygame.image.load("ggirl.jpg")
pygame.display.set_icon(icon)
'''在循环之前感知屏幕的大小，并把它赋值给当前的游戏。'''
vInfo = pygame.display.Info()
size = width, height = 600, 400
speed = [1, 1]
BLACK = 0, 0, 0
screen = pygame.display.set_mode(size, pygame.RESIZABLE)
pygame.display.set_caption("Pygame壁球鼠标控制模式")
# 将filename路径下的图像载入游戏，支持JPG、PNG等13种格式
ball = pygame.image.load("doramon.gif")
ballrect = ball.get_rect()
fps = 500  # frame per second 每秒帧率参数
fclock = pygame.time.Clock()  # 创建一个Clock对象，用于操作时间
still = False
bgcolor = pygame.Color("black")


def RGBChannel(a):
    return 0 if a < 0 else (255 if a > 255 else int(a))


while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
            """ pygame中对每个输入的按键设置了名字"""
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                speed[0] = speed[0] if speed[0] == 0 else (abs(speed[0]) - 1) * int(speed[0] / abs(speed[0]))
            elif event.key == pygame.K_RIGHT:
                speed[0] = speed[0] + 1 if speed[0] > 0 else speed[0] - 1
            elif event.key == pygame.K_UP:
                speed[1] = speed[1] + 1 if speed[1] > 0 else speed[1] - 1
            elif event.key == pygame.K_DOWN:
                speed[1] = speed[1] if speed[1] == 0 else (abs(speed[1]) - 1) * int(speed[1] / abs(speed[1]))
                '''增加了使用esc退出的功能'''
            elif event.key == pygame.K_ESCAPE:
                sys.exit()
        elif event.type == pygame.VIDEORESIZE:
            size = width, height = event.size[0], event.size[1]
            screen = pygame.display.set_mode(size, pygame.RESIZABLE)
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:
                still = True  # 鼠标左键按下，则小球停止运动，still设置为True
        elif event.type == pygame.MOUSEBUTTONUP:
            still = False  # 鼠标左键释放，则小球继续运动，still设置为False
            if event.button == 1:
                ballrect = ballrect.move(event.pos[0] - ballrect.left, event.pos[1] - ballrect.top)
                # 使用move控制小球的矩形继续移动，两个参数为小球移动的相对距离
        elif event.type == pygame.MOUSEMOTION:  # 当鼠标移动时，小球也和鼠标一起移动，利用Move函数实现
            if event.buttons[0] == 1:
                ballrect = ballrect.move(event.pos[0] - ballrect.left, event.pos[1] - ballrect.top)
    '''对于小球的运动，增加判断'''
    if pygame.display.get_active() and not still:
        ballrect = ballrect.move(speed[0], speed[1])
    """  实现壁球的反弹运动 """
    if ballrect.left < 0 or ballrect.right > width:
        speed[0] = -speed[0]
        # 对于在边缘卡顿的情况进行了修正
        if ballrect.right > width and ballrect.right + speed[0] > ballrect.right:
            speed[0] = -speed[0]
    if ballrect.top < 0 or ballrect.bottom > height:
        speed[1] = -speed[1]
        if ballrect.bottom > height and ballrect.bottom + speed[1] > ballrect.bottom:
            speed[1] = - speed[1]

    '''色彩修改'''
    bgcolor.r = RGBChannel(ballrect.left * 255 / width)
    bgcolor.g = RGBChannel(ballrect.top * 255 / height)
    bgcolor.b = RGBChannel(min(speed[0], speed[1]) * 255 / max(speed[0], speed[1]))
    screen.fill(bgcolor)
    screen.blit(ball, ballrect)
    pygame.display.update()
    fclock.tick(fps)
