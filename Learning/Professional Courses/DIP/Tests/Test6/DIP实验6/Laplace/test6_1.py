import imageio
import numpy as np
import cv2 as cv
from PIL import Image
from matplotlib import pyplot as plt


def readImg():
    return cv.imread('blurry_moon.tif')


def myLaplace():
    # 1.读入图片，处理灰度
    img = readImg()
    img_grey = cv.cvtColor(img, cv.COLOR_RGB2GRAY)

    # 2. 存入数组，并设置宽和高
    img_gaus = cv.GaussianBlur(img_grey, (3, 3), 0, 0)
    img_grey = np.array(img_gaus)
    weight, height = img.shape[:2]

    img_pad = np.pad(img_grey, ((1, 1), (1, 1)), 'edge')

    arr = np.array([[0, 1, 0], [1, -4, 1], [0, 1, 0]])
    img_out = np.zeros((weight, height))
    for i in range(weight - 2):
        for j in range(height - 2):
            img_out[i, j] = np.sum(img_pad[i:i + 3, j:j + 3] * arr)
            if img_out[i, j] < 0:
                img_out[i, j] = 0

    img_sharp = img_grey - img_out
    cv.imshow('sharp', img_sharp)
    cv.imwrite('my_sharp.jpg', img_sharp)
    cv.waitKey(0)


def lab_Laplace():
    img = readImg()
    img_gaus = cv.GaussianBlur(img, (3, 3), 0, 0)

    img_grey = cv.cvtColor(img_gaus, cv.COLOR_RGB2GRAY)

    img_lap = cv.Laplacian(img_grey, cv.CV_16S, 3)
    img_abs = cv.convertScaleAbs(img_lap)
    _, img_out = cv.threshold(img_abs, 0, 255, cv.THRESH_BINARY)
    # cv.namedWindow('pic',cv.WINDOW_AUTOSIZE)
    # cv.imshow('pic',img)
    # cv.namedWindow('out_pic', cv.WINDOW_AUTOSIZE)
    # cv.imshow('out_pic', img_out)
    cv.imwrite('lab_sharp.jpg', img_out)
    cv.waitKey(0)


if __name__ == "__main__":
    lab_Laplace()
    myLaplace()
    img = cv.imread('blurry_moon.tif')
    img_my = cv.imread('my_sharp.jpg')
    img_lab = cv.imread('lab_sharp.jpg')
    # (540, 466, 3)
    img_combine = np.zeros((540 * 2, 466, 3))  # 竖着拼接
    img_combine[:540, :, :] = img.copy()  # 原图在上
    # img_combine[540:1080, :, :] = img_my.copy()  # 调库在中
    img_combine[:540, :, :] = img_lab.copy()  # 调库在下
    img_combine = np.array(img_combine, dtype=np.uint8)  # 将pj1数组元素数据类型的改为"uint8"
    plt.imshow(img_combine)  # 查看拼接情况
    plt.show()
