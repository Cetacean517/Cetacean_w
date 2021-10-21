import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt


def readImg(src, color=0):
    return cv.imread(src, color)


def showImg(title, img):
    cv.namedWindow(title, cv.WINDOW_AUTOSIZE)
    cv.imshow(title, img)


def saveImg(title, img, type='jpg'):
    cv.imwrite(title + '.' + type, img)


def FFT(img):
    img_f = np.fft.fft2(img)
    img_fs = np.fft.fftshift(img_f)  # 图像傅里叶变换并移到图像中央位置
    # img_fs = np.log(np.abs(img_fs))
    return img_fs

    # plt.subplot(121), plt.imshow(img_f, 'gray'), plt.title('original')
    # plt.subplot(122), plt.imshow(img_fs, 'gray'), plt.title('center')
    # plt.show()


if __name__ == "__main__":

    img = readImg('cameraman.tif')
    img_str = readImg('stripy_cameraman.png')

    weight, height = img.shape[:2]
    arr = FFT(img)
    arr_str = FFT(img_str)


    arr_str[80:110, 110:120] = 0
    arr_str[140:160, 135:145] = 0

    img_back = np.fft.ifftshift(arr_str)
    img_back = np.fft.ifft2(img_back)# 出来的是复数，无法显示
    img_back = np.abs(img_back)

    plt.subplot(121), plt.imshow(img_back, 'gray'), plt.title('img back')
    plt.show()

    print('done')