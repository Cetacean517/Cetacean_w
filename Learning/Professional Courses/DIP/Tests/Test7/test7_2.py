import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt


def readImg(src):
    return cv.imread(src, cv.IMREAD_COLOR)


def grayImg(img):
    # return cv.cvtColor(img,cv.COLOR_RGB2GRAY)
    return img


def showImg(title, img):
    cv.namedWindow(title, cv.WINDOW_AUTOSIZE)
    cv.imshow(title, img)


def saveImg(title, img, type='jpg'):
    cv.imwrite(title + '.' + type, img)


if __name__ == "__main__":
    img = readImg('araras.jpg')
    # img_r,img_g,img_b = cv.split(img)
    img_r = img[:, :, 0]
    img_g = img[:, :, 1]
    img_b = img[:, :, 2]

    showImg('r', grayImg(img_r))
    showImg('g', grayImg(img_g))
    showImg('b', grayImg(img_b))

    saveImg('r.png', grayImg(img_r))
    saveImg('g.png', grayImg(img_g))
    saveImg('b.png', grayImg(img_b))

    cv.waitKey(0)
