import numpy as np


def file2array(path, delimiter=','):
    # delimiter是数据分隔符
    fp = open(path, 'r', encoding='utf-8')
    string = fp.read()
    # string是一行字符串，该字符串包含文件所有内容
    fp.close()
    row_list = string.splitlines()
    # splitlines默认参数是‘\n’
    data_list = [[float(i) for i in row.strip().split(delimiter)] for row in row_list]
    return np.array(data_list)


TrainSample = file2array('./dataanalysis/test/MTL_White_test.dat')
print("TrainSample:")
print(TrainSample)
print("TrainSample's shape", TrainSample.shape)

k = 200
TrainSub = TrainSample.reshape(k, int(3304 * 800 / k))
print("TrainSub:")
print(TrainSub)
