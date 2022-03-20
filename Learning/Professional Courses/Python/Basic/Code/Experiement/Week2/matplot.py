import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.axisartist.axislines import Subplot
from scipy import interpolate


def smooth_plot():
    fig = plt.figure()  # 创建一个figure
    ax = Subplot(fig, 111)  # 利用Subplot将figure加入ax
    fig.add_axes(ax)
    ax.axis['bottom'].set_axisline_style("->", size=1.5)  # x轴加上箭头
    ax.axis['left'].set_axisline_style("->", size=1.5)  # y轴加上上箭头
    ax.axis['top'].set_visible(False)  # 去除上方坐标轴
    ax.axis['right'].set_visible(False)  # 去除右边坐标轴
    plt.show()  # show图像


if __name__ == '__main__':
    smooth_plot()
