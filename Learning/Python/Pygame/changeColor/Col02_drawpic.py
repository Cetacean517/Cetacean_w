# pygame最小运行框架
import pygame
import sys
from math import pi

pygame.init()
screen = pygame.display.set_mode((600, 400))
pygame.display.set_caption("Pygame图形绘制")
GOLD = 255, 251, 0
RED = pygame.Color('red')
WHITE = 255, 255, 255
GREEN = pygame.Color('green')

# r1rect = pygame.draw.rect(screen, GOLD, (100, 100, 200, 100), 5)
# r2rect = pygame.draw.rect(screen, RED, (210, 210, 200, 100), 0)
# p = pygame.draw.rect(screen, pygame.Color('purple'),[(0,0,0),(1,1,1),(2,2,2)],2)

e1rect = pygame.draw.ellipse(screen, GREEN, (50, 50, 500, 300), 3)
c1rect = pygame.draw.circle(screen, GOLD, (200, 180), 30, 5)
c1rect = pygame.draw.circle(screen, GOLD, (400, 180), 30)
r1rect = pygame.draw.rect(screen, RED, (170, 130, 60, 10), 3)
r1rect = pygame.draw.rect(screen, RED, (170, 130, 60, 10))
plist = [(295, 170), (285, 250), (260, 280), (315, 250), (305, 170)]
l1rect = pygame.draw.lines(screen, GOLD, True, plist, 2)
a1rect = pygame.draw.arc(screen, RED, (200, 220, 200, 100), 1.4 * pi, 1.9 * pi, 3)
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
    pygame.display.update()
