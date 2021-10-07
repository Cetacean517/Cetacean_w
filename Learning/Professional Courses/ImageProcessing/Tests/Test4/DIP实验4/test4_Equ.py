import time

import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt


def origin_grey(img):
    gram = {}
    row, col = img.shape[:2]
    # 统计灰度表
    for i in range(row):
        for j in range(col):
            k = img[i][j]
            if k in gram:
                gram[k] += 1
            else:
                gram[k] = 1
    # 建立排序后的灰度表
    sort_gram = {}
    sort_list = sorted(gram)
    for j in range(len(sort_list)):
        sort_gram[sort_list[j]] = gram[sort_list[j]]
    return sort_gram


def equ_grey(gram, img):
    rols, cols = img.shape[:2]
    # 建立概率分布的表
    pcharm = {}
    for i in gram.keys():
        pcharm[i] = gram[i] / (rols * cols)

    temp = 0
    for j in pcharm.keys():
        temp += pcharm[j]
        pcharm[j] = max(gram) * temp

    out_img = np.zeros(shape=(rols, cols), dtype=np.uint8)

    for m in range(rols):
        for n in range(cols):
            out_img[m][n] = pcharm[img[m][n]]
    return out_img


def myHist(img):
    rols, cols = img.shape[:2]
    myHist = np.zeros([256], np.uint64)
    for i in range(rols):
        for j in range(cols):
            myHist[img[i][j]] += 1
    return myHist


def draw_gram(originHist, newHist, img, after):
    x = np.arange(256)
    # 绘制灰度直方图
    plt.figure(num=1)
    plt.subplot(2, 2, 1)
    plt.plot(x, originHist, 'r', linewidth=2, c='black')
    plt.title("Before")
    plt.ylabel("number of pixels")
    plt.subplot(2, 2, 3)
    plt.plot(x, newHist, 'r', linewidth=2, c='black')
    plt.title("After")
    plt.ylabel("number of pixels")
    plt.subplot(2, 2, 2)
    plt.imshow(img, cmap=plt.cm.gray)
    plt.title('Before')
    plt.subplot(2, 2, 4)
    plt.imshow(after, cmap=plt.cm.gray)
    plt.title('After')
    plt.show()


def do_school():
    img = cv.imread('school.png', cv.IMREAD_GRAYSCALE)
    # 计算原图灰度直方图
    og = origin_grey(img)
    school = equ_grey(og, img)
    originHist = myHist(img)
    newHist = myHist(school)
    draw_gram(originHist, newHist, img, school)
    cv.imwrite('my_school.png', school)
    return


def do_baby():
    img = cv.imread('baby.png', cv.IMREAD_GRAYSCALE)
    og = origin_grey(img)
    baby = equ_grey(og, img)
    originHist = myHist(img)
    newHist = myHist(baby)
    draw_gram(originHist, newHist, img, baby)
    cv.imwrite('my_baby.png', baby)
    return


def do_hill():
    img = cv.imread('hill.jpg', cv.IMREAD_GRAYSCALE)
    # 计算原图灰度直方图
    og = origin_grey(img)
    hill = equ_grey(og, img)
    originHist = myHist(img)
    newHist = myHist(hill)
    draw_gram(originHist, newHist, img, hill)
    cv.imwrite('my_hill.png', hill)
    return


def mat_change(img):
    return np.hstack((img, cv.equalizeHist(img)))


def do_mat_school():
    school = cv.imread('school.png', cv.IMREAD_GRAYSCALE)
    school = mat_change(school)
    cv.imwrite('mat_school.png', school)
    return


def do_mat_baby():
    baby = cv.imread('baby.png', cv.IMREAD_GRAYSCALE)
    baby = mat_change(baby)
    cv.imwrite('mat_baby.png', baby)
    return


def do_mat_hill():
    hill = cv.imread('hill.jpg', cv.IMREAD_GRAYSCALE)
    hill = mat_change(hill)
    cv.imwrite('my_hill.png', hill)
    return


def valid(func1, title):
    begin = time.time()
    func1()
    rest = time.time() - begin
    print(title + '花费的时间：' + str(rest))
    return


if __name__ == '__main__':
    valid(do_school, 'my_school')
    valid(do_baby, 'my_baby')
    valid(do_hill, 'my_hill')
    valid(do_mat_school, 'my_mat_school')
    valid(do_mat_baby, 'my_mat_baby')
    valid(do_mat_hill, 'my_mat_hill')
