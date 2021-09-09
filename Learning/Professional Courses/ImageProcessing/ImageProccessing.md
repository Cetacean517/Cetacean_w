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


