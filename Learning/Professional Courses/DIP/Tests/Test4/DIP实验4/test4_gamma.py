import cv2 as cv
import numpy as np
from numpy import double
from geskima import exposure
import time

# def to_grey(img):
#     return cv.cvtColor(img, cv.COLOR_RGB2GRAY)
# def to_color(img):
#     return cv.cvtColor(img, cv.COLOR_GRAY2RGB)

# 第一部分：自己实现
# 方法一：建立查找表，替换
# 建立自己的查找表
def build_table(table, gamma):
    for i in range(255):
        temp = double(i) / 255
        temp = pow(temp, gamma)
        table[0, i] = temp * 255
    return


def produce_img_gamma(gamma, img):
    chart = np.zeros((1, 256))  # 利用numpy一个256个元素的数组
    build_table(chart, gamma)  # 构造gamma查找表
    # img = to_grey(img)
    rows, cols, counts = img.shape
    for i in range(rows):
        for j in range(cols):
            for k in range(counts):
                img[i, j, k] = chart[0, img[i, j, k]]
    return img


def produce_light():
    light = cv.imread('light.tif')
    img = produce_img_gamma(2, light)
    # cv.namedWindow('gamma_table', cv.WINDOW_NORMAL)
    # cv.imshow('gamma_table', img)
    # cv.waitKey()
    cv.imwrite("gamma_table_light.jpg", img)


# 方法二：直接替换
def gamma_direct(gamma, img):
    direct = img.copy()
    direct /= 255.
    direct = pow(direct, gamma)
    direct *= 255
    direct = direct.astype(np.uint8)
    return direct


def produce_dark():
    img = cv.imread("dark.png").astype(np.float64)
    result = gamma_direct(0.5, img)
    # cv.imshow("gamma_direct", result)
    # cv.waitKey(0)
    cv.imwrite("gamma_direct_dark.jpg", result)


def gamma_sk_light():
    img = cv.imread('light.tif')
    result = exposure.adjust_gamma(img, 2)
    # cv.imshow("gamma_sk", result)
    # cv.waitKey(0)
    cv.imwrite("gamma_sk_light.jpg", result)


def gamma_sk_dark():
    img = cv.imread('dark.png')
    result = exposure.adjust_gamma(img, 0.5)
    # cv.imshow("gamma_sk", result)
    # cv.waitKey(0)
    cv.imwrite("gamma_sk_dark.jpg", result)


def valid(func1, title):
    begin = time.time()
    func1()
    rest = time.time() - begin
    print(title + '花费的时间：' + str(rest))
    return


if __name__ == '__main__':
    valid(produce_light, '查找表light')
    valid(produce_dark, '直接dark')
    valid(gamma_sk_light, 'sk库light')
    valid(gamma_sk_dark, 'sk库dark')
