""" 用一行列表推导式，生成100以内的素数列表"""
from math import sqrt

a = [p for p in range(2, 100) if 0 not in [p % d for d in range(2, int(sqrt(p) + 1))]]
print(a)
