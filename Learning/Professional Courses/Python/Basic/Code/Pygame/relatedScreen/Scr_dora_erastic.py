import pygame
import sys

pygame.init()
'''改造1：在循环之前感知屏幕的大小，并把它赋值给当前的游戏。'''
vInfo = pygame.display.Info()
size = width, height = 600, 400
speed = [1, 1]
BLACK = 0, 0, 0
# screen = pygame.display.set_mode(size, pygame.NOFRAME)
screen = pygame.display.set_mode(size, pygame.RESIZABLE)
# screen = pygame.display.set_mode(size, pygame.FULLSCREEN)
pygame.display.set_caption("Pygame壁球可伸缩模式")
# 将filename路径下的图像载入游戏，支持JPG、PNG等13种格式
ball = pygame.image.load("doramon.gif")
ballrect = ball.get_rect()
fps = 500   # frame per second 每秒帧率参数
fclock = pygame.time.Clock()    # 创建一个Clock对象，用于操作时间

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
            """ pygame中对每个输入的按键设置了名字"""
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                speed[0] = speed[0] if speed[0] == 0 else (abs(speed[0]) - 1) * int(speed[0] /abs(speed[0]))
            elif event.key == pygame.K_RIGHT:
                speed[0] = speed[0] + 1 if speed[0] > 0 else speed[0] - 1
            elif event.key == pygame.K_UP:
                speed[1] = speed[1] + 1 if speed[1] > 0 else speed[1] - 1
            elif event.key == pygame.K_DOWN:
                speed[1] = speed[1] if speed[1] == 0 else (abs(speed[1]) - 1) * int(speed[1] /abs(speed[1]))
                '''改造1：增加了使用esc退出的功能'''
            elif event.key == pygame.K_ESCAPE:
                sys.exit()
        elif event.type == pygame.VIDEORESIZE:
            size = width, height = event.size[0], event.size[1]
            screen = pygame.display.set_mode(size, pygame.RESIZABLE)

    ballrect = ballrect.move(speed[0], speed[1])
    """  实现壁球的反弹运动 """
    if ballrect.left < 0 or ballrect.right > width:
        speed[0] = -speed[0]
    if ballrect.top < 0 or ballrect.bottom > height:
        speed[1] = -speed[1]
    screen.fill(BLACK)
    screen.blit(ball, ballrect)
    pygame.display.update()
    fclock.tick(fps)

