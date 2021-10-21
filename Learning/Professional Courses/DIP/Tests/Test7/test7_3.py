import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt


def readImg(src, color=3):
    return cv.imread(src, color)


def showImg(title, img):
    cv.namedWindow(title, cv.WINDOW_AUTOSIZE)
    cv.imshow(title, img)


def saveImg(title, img, type='jpg'):
    cv.imwrite(title + '.' + type, img)


def RGB2HSI(img):
    weight, height = img.shape[:2]
    b, g, r = cv.split(img)
    # 归一化[0,1]
    b = b / 255.0
    g = g / 255.0
    r = r / 255.0
    img_HSI = img.copy()
    H, S, I = cv.split(img_HSI)
    for i in range(weight):
        for j in range(height):
            num = 0.5 * ((r[i, j] - g[i, j]) + (r[i, j] - b[i, j]))
            den = np.sqrt((r[i, j] - g[i, j]) ** 2 + (r[i, j] - b[i, j]) * (g[i, j] - b[i, j]))
            angle = float(np.arccos(num / den))

            if den == 0:
                H = 0
            elif b[i, j] <= g[i, j]:
                H = angle
            else:
                H = 2 * 3.1415926 - angle

            min_RGB = min(min(b[i, j], g[i, j]), r[i, j])
            sum = b[i, j] + g[i, j] + r[i, j]
            if sum == 0:
                S = 0
            else:
                S = 1 - 3 * min_RGB / sum

            H = H / (2 * 3.14159265)
            I = sum / 3.0
            # 扩充到255，一般H在[0,2pi],S和I在[0,1]之间
            img_HSI[i, j, 0] = H * 255
            img_HSI[i, j, 1] = S * 255
            img_HSI[i, j, 2] = I * 255
        return img_HSI


def HSI2RGB(img):
    weight,height = img.shape[:2]
    img_rgb = img.copy()
    H,S,I = cv.split(img)
    [H, S, I] = [i / 255.0 for i in ([H, S, I])]
    R, G, B = H, S, I
    for i in range(weight):
        h = H[i] * 2 * np.pi

        # H大于等于0小于120度时
        a1 = h >= 0
        a2 = h < 2 * np.pi / 3
        a = a1 & a2  # 第一种情况
        tmp = np.cos(np.pi / 3 - h)
        b = I[i] * (1 - S[i])
        r = I[i] * (1 + S[i] * np.cos(h) / tmp)
        g = 3 * I[i] - r - b
        B[i][a] = b[a]
        R[i][a] = r[a]
        G[i][a] = g[a]

        # H大于等于120度小于240度
        a1 = h >= 2 * np.pi / 3
        a2 = h < 4 * np.pi / 3
        a = a1 & a2  # 第二种情况
        tmp = np.cos(np.pi - h)
        r = I[i] * (1 - S[i])
        g = I[i] * (1 + S[i] * np.cos(h - 2 * np.pi / 3) / tmp)
        b = 3 * I[i] - r - g
        R[i][a] = r[a]
        G[i][a] = g[a]
        B[i][a] = b[a]

        # H大于等于240度小于360度
        a1 = h >= 4 * np.pi / 3
        a2 = h < 2 * np.pi
        a = a1 & a2  # 第三种情况
        tmp = np.cos(5 * np.pi / 3 - h)
        g = I[i] * (1 - S[i])
        b = I[i] * (1 + S[i] * np.cos(h - 4 * np.pi / 3) / tmp)
        r = 3 * I[i] - g - b
        B[i][a] = b[a]
        G[i][a] = g[a]
        R[i][a] = r[a]
    img_rgb[:, :, 0] = B * 255
    img_rgb[:, :, 1] = G * 255
    img_rgb[:, :, 2] = R * 255
    return img_rgb


if __name__ == "__main__":
    img = readImg('stream.jpg', 1)
    (b, g, r) = cv.split(img)  # 通道分解
    bH = cv.equalizeHist(b)
    gH = cv.equalizeHist(g)
    rH = cv.equalizeHist(r)
    result = cv.merge((bH, gH, rH), )  # 通道合成
    res = np.hstack((img, result))
    cv.imshow('dst', res)
    cv.waitKey(0)

    #
    img = readImg('stream.jpg')
    img_HSI = RGB2HSI(img)
    (H,S,I) = cv.split(img)
    HH = cv.equalizeHist(H)
    SH = cv.equalizeHist(S)
    IH = cv.equalizeHist(I)
    img_nHSI = cv.merge((H,S,IH), )

    # img_nHSI = img_HSI.copy()
    # weight, height = img.shape[:2]
    # for i in range(weight):
    #     for j in range(height):
    #         img_nHSI[i, j, 2] = img_equ[i, j]

    img_RGB = HSI2RGB(img_nHSI)
    img_out = np.hstack((img, img_RGB))
    # stacking images side-by-side
    #
    showImg('my', img_out)
    cv.waitKey(0)
