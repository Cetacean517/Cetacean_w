import cv2 as cv
import numpy as np


def readImg(src, color=3):
    return cv.imread(src, color)


def showImg(title, img):
    cv.namedWindow(title, cv.WINDOW_AUTOSIZE)
    cv.imshow(title, img)


def saveImg(title, img, type='jpg'):
    cv.imwrite(title + '.' + type, img)


def lab_sobel(img, title):
    img = readImg(img, 0)
    img_sobx = cv.Sobel(img, cv.CV_64F, 1, 0, ksize=3)
    img_soby = cv.Sobel(img, cv.CV_64F, 0, 1, ksize=3)
    img_sobxy = np.sqrt(img_sobx ** 2 + img_soby ** 2)
    showImg(title, img_sobxy)
    saveImg(title, img_sobxy)


def my_sobel(img, title):
    img = readImg(img)
    img = np.array(img)
    weight, height = img.shape[:2]
    img_new = np.zeros((weight, height))
    img_newx = np.zeros(img.shape[:2])
    img_newy = np.zeros(img.shape[:2])
    sob_x = np.array(([-1, 0, 1], [-2, 0, 2], [-1, 0, 1]))
    sob_y = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])
    for i in range(weight - 2):
        for j in range(height - 2):
            img_newx[i + 1, j + 1] = abs(np.sum(img[i:i + 3, j:j + 3] * sob_x))
            img_newy[i + 1, j + 1] = abs(np.sum(img[i:i + 3, j:j + 3] * sob_y))
            img_new[i + 1, j + 1] = (img_newx[i + 1, j + 1] * img_newx[i + 1, j + 1] + img_newy[i + 1, j + 1] * img_newy[i + 1, j + 1]) ** 0.5
    img_newxy = np.uint8(img_new)
    showImg(title, img_newxy)
    saveImg(title, img_newxy)


if __name__ == "__main__":
    lab_sobel('magic.png', 'magic_lab')
    my_sobel('magic.png', 'magic_my')
    lab_sobel('lane.png', 'lane_lab')
    my_sobel('lane.png', 'lane_my')
    lab_sobel('plate.png', 'plate_lab')
    my_sobel('plate.png', 'plate_my')
    cv.waitKey(0)
