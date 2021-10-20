import numpy as np

'''补充pad()函数及使用
方法参数：pad(array, pad_width, mode, **kwargs)
方法返回：填充后的数组
参数解释：
array：表示需要填充的数组；
pad_width：表示每个轴（axis）边缘需要填充的数值数目。
参数输入方式：
（(before_1, after_1), … (before_N, after_N)），
其中(before_1, after_1)表示第1轴两边缘分别填充before_1个和after_1个数值。

mode：表示填充的方式（取值：str字符串或用户提供的函数）
mode中的填充方式：
constant’——表示连续填充相同的值，每个轴可以分别指定填充值，constant_values=（x, y）时前面用x填充，后面用y填充，缺省值填充0
‘edge’——表示用边缘值填充
‘linear_ramp’——表示用边缘递减的方式填充
‘maximum’——表示最大值填充
‘mean’——表示均值填充
‘median’——表示中位数填
‘minimum’——表示最小值填充
‘reflect’——表示对称填充
‘symmetric’——表示对称填充
‘wrap’——表示用原数组后面的值填充前面，前面的值填充后面
'''

array = np.array([[1, 1], [2, 2]])

"""
((1,1),(2,2))表示在二维数组array第一维（此处便是行）前面填充1行，最后面填充1行；
                 在二维数组array第二维（此处便是列）前面填充2列，最后面填充2列
constant_values=(0,3) 表示第一维填充0，第二维填充3
"""

ndarray = np.pad(array, ((1, 1), (2, 2)), 'constant', constant_values=(0, 3))
img_pad = np.pad(array,((1,1),(1,1)),'edge')

print("array", array)
print("ndarray=", ndarray)
print("ndarray=", img_pad)
