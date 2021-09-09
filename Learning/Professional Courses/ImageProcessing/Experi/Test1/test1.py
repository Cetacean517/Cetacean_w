import numpy as np
import cv2 as cv

# 将彩色图片保存为灰色图片
# img = cv.imread('letter.jpg',0)
# cv.imshow('letter',img)
# k = cv.waitKey(0) & 0xFF
# if k == 27:
#     cv.destroyAllWindows()
# elif k == ord('s'):
#     cv.imwrite('lettergray.jpg',img)
#     cv.destroyAllWindows()

# # 读取彩色图像，对于BGR图像它存储的是blue,green,red的数组；
# # 对于灰度图像，只返回相应的灰度。
# # 以下多用于数组区域的访问，单个访问常用Numpy数组方法arrya.item()和array.itemset()
# img = cv.imread('letter.jpg')
# px = img[100,100]
# print(px)
# blue = img[100,100,0]
# print(blue)

# # Numpy方法
# img = cv.imread('letter.jpg')
# # 访问red值
# print(img.item(10,10,2))
# # 修改red值
# img.itemset((10,10,2),100)
# print(img.item(10,10,2))

# 图像感兴趣区域ROI
# 抠图再拼接
img = cv.imread('letter.jpg')
# 第一个参数是高，第二个参数是宽；起始20，一个字母宽90，高100
a = img[0:100,20:110]
g = img[0:100,475:580]
i = img[100:200,130:200]
n = img[100:200,475:580]
q = img[200:300,185:280]
u = img[200:300,470:560]
w = img[300:400,185:280]
y = img[300:400,350:445]
one = img[400:490,120:190]
two = img[400:490,190:260]
nine = img[490:580,340:400]
zero = img[490:580,400:485]
blank = img[500:590,500:600]

name = cv.hconcat([w,a,n,g,y,u,q,i,n,g],img)
print(name.shape)

number = cv.hconcat([blank,blank,one,nine,one,two,zero,one,nine,one,blank,blank],img)
print(number.shape)
add = cv.vconcat([number,name])
cv.imwrite('intro.jpg',add)


cv.namedWindow('cut',cv.WINDOW_AUTOSIZE)
cv.imshow('cut',add)
cv.waitKey(0)
cv.destroyAllWindows()




