import numpy as np


def label(filename):
    data = np.loadtxt(filename)
    a = np.array(data)
    b = np.abs(a)  # 取绝对值
    return -np.sort(-b)  # 降序排列


if __name__ == '__main__':
    MTLLabel = label('./dataanalysis/label/MTL_White.dat')
    CMTLLabel = label('./dataanalysis/label/CMTL_White.dat')
    CEMTLLabel = label('./dataanalysis/label/CEMTL_White.dat')
