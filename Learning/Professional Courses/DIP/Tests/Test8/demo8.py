# 导入的库
from moviepy.editor import VideoFileClip
import numpy as np
import cv2 as cv

"""
一些变量的设置
"""
gk_size = 5  # 高斯变化内核大小
canny_low = 50  # Canny边缘检测的最低阈值
canny_high = 150  # Canny边缘检测的最高阈值
rho_step = 1  # rho_step的步长，即直线到图像原点(0,0)点的距离
theta = np.pi / 180  # theta的范围（角度）
threshold = 15  # 累加器中的值高于它时才认为是一条直线
min_len = 40  # 线的最短长度，比这个短的都被忽略
max_gap = 20  # 两条直线之间的最大间隔，小于此值，认为是一条直线


def roi_mask(img, intere_vec):                  # img是输入的图像，intere_vec是兴趣区的四个点的坐标（三维的数组）
    mask = np.zeros_like(img)                   # 创建副本：生成与输入图像相同大小的图像，并使用0填充,图像为黑色
    if len(img.shape) > 2:
        img_channel = img.shape[2]              # 获取图片宽和高
        mask_color = (255,) * img_channel       # 如果 img_channel=3, 则为(255,255,255)
    else:
        mask_color = 255
    cv.fillPoly(mask, intere_vec, mask_color)   # 使用白色填充多边形，形成蒙板
    img_mask = cv.bitwise_and(img, mask)        # img&mask，经过此操作后，兴趣区域以外的部分被蒙住了，只留下兴趣区域的图像
    return img_mask


def draw_roi(img, intere_vec):
    cv.polylines(img, intere_vec, True, [255, 0, 0], thickness=2)


def draw_lines(img, lines, color=[255, 0, 0], thickness=2):
    for line in lines:
        for x1, y1, x2, y2 in line:
            cv.line(img, (x1, y1), (x2, y2), color, thickness)


def hough_lines(img, step, theta_h, thresh, min_line_len, max_gap):
    lines = cv.HoughLinesP(img, step, theta_h, thresh, np.array([]), minLineLength=min_line_len,maxLineGap=max_gap)  # 函数输出的直接就是一组直线点的坐标位置（每条直线用两个点表示[x1,y1],[x2,y2]）
    img_line = np.zeros((img.shape[0], img.shape[1], 3), dtype=np.uint8)  # 生成绘制直线的绘图板，黑底
    add_line(img_line, lines)
    return img_line


def add_line(img, lines, color=[255, 0, 0], thickness=8):
    left_lines, right_lines = [], []                # 用于存储左边和右边的直线
    for line in lines:                              # 对直线进行分类
        for x1, y1, x2, y2 in line:
            k = (y2 - y1) / (x2 - x1)
            if k < 0:
                left_lines.append(line)
            else:
                right_lines.append(line)

    if len(left_lines) <= 0 or len(right_lines) <= 0:
        return img

    clean_lines(left_lines, 0.1)    # 弹出左侧不满足斜率要求的直线
    clean_lines(right_lines, 0.1)   # 弹出右侧不满足斜率要求的直线
    left_points = [(x1, y1) for line in left_lines for x1, y1, x2, y2 in line]                      # 提取左侧直线族中的所有的第一个点
    left_points = left_points + [(x2, y2) for line in left_lines for x1, y1, x2, y2 in line]        # 提取左侧直线族中的所有的第二个点
    right_points = [(x1, y1) for line in right_lines for x1, y1, x2, y2 in line]                    # 提取右侧直线族中的所有的第一个点
    right_points = right_points + [(x2, y2) for line in right_lines for x1, y1, x2, y2 in line]     # 提取右侧侧直线族中的所有的第二个点

    left_vtx = calc_lane_intere_vec(left_points, 325, img.shape[0])           # 拟合点集，生成直线表达式，并计算左侧直线在图像中的两个端点的坐标
    right_vtx = calc_lane_intere_vec(right_points, 325, img.shape[0])         # 拟合点集，生成直线表达式，并计算右侧直线在图像中的两个端点的坐标

    cv.line(img, left_vtx[0], left_vtx[1], color, thickness)    # 画出直线
    cv.line(img, right_vtx[0], right_vtx[1], color, thickness)  # 画出直线


# 将不满足斜率要求的直线弹出
def clean_lines(lines, threshold):
    slope = []
    for line in lines:
        for x1, y1, x2, y2 in line:
            k = (y2 - y1) / (x2 - x1)
            slope.append(k)
    while len(lines) > 0:
        mean = np.mean(slope)                   # 计算斜率的平均值，因为后面会将直线和斜率值弹出
        diff = [abs(s - mean) for s in slope]   # 计算每条直线斜率与平均值的差值
        idx = np.argmax(diff)                   # 计算差值的最大值的下标
        if diff[idx] > threshold:               # 将差值大于阈值的直线弹出
            slope.pop(idx)                      # 弹出斜率
            lines.pop(idx)                      # 弹出直线
        else:
            break


# 拟合点集，生成直线表达式，并计算直线在图像中的两个端点的坐标
def calc_lane_intere_vec(point_list, y_min, y_max):
    x = [p[0] for p in point_list]  # 提取x
    y = [p[1] for p in point_list]  # 提取y
    fit = np.polyfit(y, x, 1)       # 用一次多项式x=a*y+b拟合这些点，fit是(a,b)
    fit_fn = np.poly1d(fit)         # 生成多项式对象a*y+b          
                                            
    x_min = int(fit_fn(y_min))  # 计算这条直线在图像中最左侧的横坐标
    x_max = int(fit_fn(y_max))  # 计算这条直线在图像中最右侧的横坐标

    return [(x_min, y_min), (x_max, y_max)]


def do_img(img):
    roi_part = np.array([[(0, img.shape[0]), (460, 325), (520, 325), (img.shape[1], img.shape[0])]])  # roi_part: 三维的数组;感兴趣区域的四个坐标
    gray = cv.cvtColor(img, cv.COLOR_RGB2GRAY)                                          # 图像转换为灰度图
    blur_gray = cv.GaussianBlur(gray, (gk_size, gk_size), 0, 0)                         # 使用高斯模糊去噪声
    edges = cv.Canny(blur_gray, canny_low, canny_high)                                  # 使用Canny进行边缘检测
    roi_edges = roi_mask(edges, roi_part)                                               # 对边缘检测的图像生成图像蒙板，去掉不感兴趣的区域，保留兴趣区
    img_line = hough_lines(roi_edges, rho_step, theta, threshold, min_len, max_gap)     # 使用霍夫直线检测，并且绘制直线
    img_out = cv.addWeighted(img, 0.8, img_line, 1, 0)                                  # 将处理后的图像与原图做融合
    return img_out


if __name__ == "__main__":
    print("start to process the video....")
    output = 'Output2.mp4'
    in_clip = VideoFileClip("2.mp4")                # 读入视频
    out_clip = in_clip.fl_image(do_img)        # 对视频进行切片
    out_clip.write_videofile(output, audio=True)    # 将处理后的视频写入新的视频文件
