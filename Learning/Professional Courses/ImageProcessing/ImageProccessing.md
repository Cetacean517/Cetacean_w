# 图像处理实验
## 实验一
> 任务1
> 利用letter.jpg中的字母和数字，生成一张图片
> 图片中第一行是自己的学号，第2行是自己姓名的拼音（留学生可以是自己名字的英文拼写）
> 要求编程实现，而不是手工处理

### 学习内容
#### 图片读取
`cv.imread('filename.jpg',0)`
  - arg1: 文件名
  - arg2: 设置图片灰度
#### 用numpy 创建一个图片 
`img2=np.full((500,800,3),(211,223,229),np.unit8)`
- arg1: 高，宽，色彩
- arg2: 具体的rgb
- arg3: 默认
#### 裁剪图片
`img[100：200 ,150:200]` 高+宽
#### 拼接图片
`cv.hconcat([img,img,img...])`
`cv.vconcat([img,img,img...])`
#### 将彩色图片保存为灰色图片
```python
img = cv.imread('letter.jpg',0)
 cv.imshow('letter',img)
 k = cv.waitKey(0) & 0xFF
 # 按0退出，按s保存
 if k == 27: 
     cv.destroyAllWindows()
 elif k == ord('s'):
     cv.imwrite('lettergray.jpg',img)
     cv.destroyAllWindows()
```

#### 显示图片 并设置窗口可调节
```python
cv.namedWindow('cut',cv.WINDOW_AUTOSIZE)
cv.imshow('cut',add)    # 前一个是窗口标题
cv.waitKey(0)
cv.destroyAllWindows()
```

#### 代码
```python
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
# print(name.shape)

number = cv.hconcat([blank,blank,one,nine,one,two,zero,one,nine,one,blank,blank],img)
# print(number.shape)
add = cv.vconcat([number,name])
cv.imwrite('intro.jpg',add)


cv.namedWindow('cut',cv.WINDOW_AUTOSIZE)
cv.imshow('cut',add)
cv.waitKey(0)
cv.destroyAllWindows()
```


