# import numpy as np
# import cv2 as cv
#
# # 将图片转为灰度图
# # https://blog.csdn.net/weixin_43635647/article/details/99625105
# img = cv.imread('finger.tif', 0)
# cv.imshow("img", img)
# cv.waitKey()
#
#
# def OTSU(img_gray, GrayScale):
#     assert img_gray.ndim == 2, "must input a gary_img"  # shape有几个数字, ndim就是多少
#     img_gray = np.array(img_gray).ravel().astype(np.uint8)
#     u1 = 0.0  # 背景像素的平均灰度值
#     u2 = 0.0  # 前景像素的平均灰度值
#     th = 0.0
#
#     # 总的像素数目
#     PixSum = img_gray.size
#     # 各个灰度值的像素数目
#     PixCount = np.zeros(GrayScale)
#     # 各灰度值所占总像素数的比例
#     PixRate = np.zeros(GrayScale)
#     # 统计各个灰度值的像素个数
#     for i in range(PixSum):
#         # 默认灰度图像的像素值范围为GrayScale
#         Pixvalue = img_gray[i]
#         PixCount[Pixvalue] = PixCount[Pixvalue] + 1
#
#     # 确定各个灰度值对应的像素点的个数在所有的像素点中的比例。
#     for j in range(GrayScale):
#         PixRate[j] = PixCount[j] * 1.0 / PixSum
#     Max_var = 0
#     # 确定最大类间方差对应的阈值
#     for i in range(1, GrayScale):  # 从1开始是为了避免w1为0.
#         u1_tem = 0.0
#         u2_tem = 0.0
#         # 背景像素的比列
#         w1 = np.sum(PixRate[:i])
#         # 前景像素的比例
#         w2 = 1.0 - w1
#         if w1 == 0 or w2 == 0:
#             pass
#         else:  # 背景像素的平均灰度值
#             for m in range(i):
#                 u1_tem = u1_tem + PixRate[m] * m
#             u1 = u1_tem * 1.0 / w1
#             # 前景像素的平均灰度值
#             for n in range(i, GrayScale):
#                 u2_tem = u2_tem + PixRate[n] * n
#             u2 = u2_tem / w2
#             # print(u1)
#             # 类间方差公式：G=w1*w2*(u1-u2)**2
#             tem_var = w1 * w2 * np.power((u1 - u2), 2)
#             # print(tem_var)
#             # 判断当前类间方差是否为最大值。
#             if Max_var < tem_var:
#                 Max_var = tem_var  # 深拷贝，Max_var与tem_var占用不同的内存空间。
#                 th = i
#     return th
#
#
# th = OTSU(img, 256)
# cv.imshow("th", img)
# cv.waitKey()
# print("使用numpy的方法：" + str(th))  # 结果为 135
#coding:utf-8
import cv2
import numpy as np
from matplotlib import pyplot as plt

image = cv2.imread("rice.tiff")
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

plt.subplot(131), plt.imshow(image, "gray")
plt.title("Before"), plt.xticks([]), plt.yticks([])
# plt.subplot(132), plt.hist(image.ravel(), 256)
# plt.title("Histogram"), plt.xticks([]), plt.yticks([])
ret1, th1 = cv2.threshold(gray, 0, 255, cv2.THRESH_OTSU)  #方法选择为THRESH_OTSU
plt.subplot(133), plt.imshow(th1, "gray")
plt.title("After"), plt.xticks([]), plt.yticks([])
plt.show()