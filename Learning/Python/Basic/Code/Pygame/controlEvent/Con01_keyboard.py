# Unit PYG04: Pygame Event Print
import pygame
import sys

pygame.init()
screen = pygame.display.set_mode((600, 400))
pygame.display.set_caption("Pygame事件处理")

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            # 由于不是每一个系统都有unicode编码，因此进行判断，为空时不打印。
            if event.unicode == '':
                print("[KEDYDOWN:]", "#", event.key, event.mod)
            else:
                print("[KEYDOWN]:", event.unicode, event.key, event.mod)
        elif event.type == pygame.MOUSEMOTION:
            print("[MOUSEMOTION]:", event.pos, event.rel, event.buttons)
        elif event.type == pygame.MOUSEBUTTONUP:
            print("[MOUSEBUTTTIONUP]:", event.pos, event.button)
        elif event.type == pygame.MOUSEBUTTONDOWN:
            print("[MOUSEBUTTONDOWN]:", event.pos, event.button)

    pygame.display.update()
