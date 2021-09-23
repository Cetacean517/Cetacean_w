import cv2 as cv
import matplotlib.pyplot as plt
import numpy as np

# 读入海报图片以及背景图片
post0 = cv.imread('wukong.jpg')
# cv.imshow('post.jpg',post0)
# cv.waitKey(10)
background = cv.imread('board2.jpg')
# cv.namedWindow('background', cv.WINDOW_NORMAL)
# cv.imshow('background', background)
# cv.waitKey(10)

# 对post进行大小变换;cv.INTER_LINEAR双线性插值法
heigth, width = post0.shape[:2]
post0 = cv.resize(post0, (740, 850), interpolation=cv.INTER_LINEAR)  # 宽，高
post0 = cv.cvtColor(post0, cv.COLOR_BGR2BGRA)
cv.imshow('resize.jpg',post0)
cv.waitKey(10)

# 进行放射变换,保存至dst
rows, cols = post0.shape[:2]
pts1 = np.float32([[0, 0], [0, 850], [740, 0], [740, 850]])
pts2 = np.float32([[0, 140], [0, 800], [740, 0], [740, 850]])
M = cv.getPerspectiveTransform(pts1, pts2)
dst = cv.warpPerspective(post0, M, (cols, rows), 0.6, borderMode=cv.BORDER_CONSTANT, borderValue=[0, 0, 0, 0.5])

plt.figure(figsize=(10, 8), dpi=80)
cv.imwrite('post.jpg', dst)

# 把图片变形之后，贴到背景上
post = cv.imread('post.jpg')
rows_b, cols_b, channels_b = post.shape
center = [938, 1950]  # 高，横

for i in range(rows_b):
    for j in range(cols_b):
        background[center[0] + i, center[1] + j] = post[i, j]
cv.namedWindow('post in bg', cv.WINDOW_NORMAL)
cv.imshow('post in bg', background)
cv.waitKey()
