import cv2 as cv
import matplotlib.pyplot as plt
import numpy as np

# 读入海报图片以及背景图片
post0 = cv.imread('wukong.jpg')

background = cv.imread('board2.jpg')
background = cv.cvtColor(background, cv.COLOR_BGR2BGRA)

# 对post进行大小变换;cv.INTER_LINEAR双线性插值法
heigth, width = post0.shape[:2]
post0 = cv.resize(post0, (740, 850), interpolation=cv.INTER_LINEAR)  # 宽，高
post0 = cv.cvtColor(post0, cv.COLOR_BGR2BGRA)

# 进行放射变换,保存至dst
rows, cols = post0.shape[:2]
pts1 = np.float32([[0, 0], [0, 850], [740, 0], [740, 850]])
pts2 = np.float32([[0, 140], [0, 800], [740, 0], [740, 850]])
M = cv.getPerspectiveTransform(pts1, pts2)
dst = cv.warpPerspective(post0, M, (cols, rows), 0.6, borderMode=cv.BORDER_CONSTANT, borderValue=(50, 50, 50, 255))
# 将边长设置成一个自定义的颜色

plt.figure(figsize=(10, 8), dpi=80)

# 把图片变形之后，贴到背景上
rows_b, cols_b, channels_b = dst.shape
center = [938, 1950]  # 高，横

for i in range(rows_b):
    for j in range(cols_b):
        if not all(dst[i, j] == [50, 50, 50, 255]):         # 通过判断，当像素点的颜色和填充色相同的时候，不进行叠加，实现黑边的去除。
            background[center[0] + i, center[1] + j] = dst[i, j]
cv.namedWindow('post in bg', cv.WINDOW_NORMAL)
cv.imshow('post in bg', background)
cv.waitKey()
