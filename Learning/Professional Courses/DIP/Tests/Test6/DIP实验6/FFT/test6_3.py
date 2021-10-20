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


import cv2
import numpy as np
import matplotlib.pyplot as plt

# img = cv2.imread("cameraman.tif")
img = readImg("cameraman.tif", 0)
print(img)
dft = cv2.dft(np.float32(img), flags = cv2.DFT_COMPLEX_OUTPUT)
dftShift = np.fft.fftshift(dft)
result = 20*np.log(cv2.magnitude(dftShift[:,:,0], dftShift[:,:,1]))

plt.subplot(121)
plt.imshow(img, cmap = 'gray')
plt.title('original')
plt.axis('off')

plt.subplot(122)
plt.imshow(result, cmap = 'gray')
plt.title('result')
plt.axis('off')

plt.show()

