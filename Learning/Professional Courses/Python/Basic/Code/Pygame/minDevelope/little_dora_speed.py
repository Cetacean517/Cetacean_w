import pygame
import sys

pygame.init()
size = width, height = 800, 600
speed = [1, 1]
BLACK = 0, 0, 0
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Pygame壁球")
# 将filename路径下的图像载入游戏，支持JPG、PNG等13种格式
ball = pygame.image.load("doramon.gif")
# dora = pygame.image.load("doramon.gif")
''' Surface对象 ball.get_rect() 
    Pygame使用内部定义的Surface额对象表示所有载入的图像，其中.get_rect()方法返回一个覆盖图像的矩形对象。
    可以设置矩形的上下左右的宽度长度的值，便于编辑图像'''
ballrect = ball.get_rect()
# dorarect = dora.get_rect()
fps = 500   # frame per second 每秒帧率参数
fclock = pygame.time.Clock()    # 创建一个Clock对象，用于操作时间

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
    """ ballrect.move(x,y)
        矩形移动一个偏移量(x,y),即在横轴方向移动x像素，纵轴方向移动y像素,xy为整数。"""
    ballrect = ballrect.move(speed[0], speed[1])
    """  实现壁球的反弹运动 """
    if ballrect.left < 0 or ballrect.right > width:
        speed[0] = -speed[0]
    if ballrect.top < 0 or ballrect.bottom > height:
        speed[1] = -speed[1]
    """ 显示窗口背景填充为color颜色，采用RGB色彩体系。
    由于壁球不断运动，运动后原有位置将默认填充白色，因此需要不断刷新背景色。"""
    screen.fill(BLACK)
    """ 将一个图像绘制在另一个图像上，即将src绘制到dest位置上。通过Rect对象引导对壁球的绘制。"""
    screen.blit(ball, ballrect)
    pygame.display.update()
    """ 控制帧速度，即窗口刷新速度，
        例如：clock.tick(100)表示每秒钟100次帧刷新
             视频中每次展示的静态图像称为帧"""
    fclock.tick(fps)

