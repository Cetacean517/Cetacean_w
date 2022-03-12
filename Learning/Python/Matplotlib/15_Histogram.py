# 直方图
# 用于概率分布，他显示一组数值序列在给定的数值范围内出现的概率
# 而柱状图只是展示各个类别的频数

# 语法
# matplotlib.pyplot.hist（）
# 参数：
# x	必填参数，数组或者数组序列。
# bins	可选参数，整数或者序列，bins 表示每一个间隔的边缘（起点和终点）默认会生成10个间隔。
# range	指定全局间隔的下限与上限值 (min,max)，元组类型，默认值为 None。
# density	如果为 True，返回概率密度直方图；默认为 False，返回相应区间元素的个数的直方图。
# histtype	要绘制的直方图类型，默认值为“bar”，可选值有 barstacked(堆叠条形图)、step(未填充的阶梯图)、stepfilled(已填充的阶梯图)。

from matplotlib import pyplot as plt
import numpy as np
# 创建图形对象和轴域对象
fig,ax = plt.subplots(1,1)
a = np.array([22,87,5,43,56,73,55,54,11,20,51,5,79,31,27])
# 绘制直方图
ax.hist(a, bins = [0,25,50,75,100]) # 数组, bins：每个间隔的边缘
# 设置坐标轴
ax.set_title("histogram of result")
ax.set_xticks([0,25,50,75,100])
ax.set_xlabel('marks')
ax.set_ylabel('no.of students')
plt.show()