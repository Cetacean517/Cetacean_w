"""已知三角形两边长和夹角，求第三边长"""

import math

x = input("输入两边和夹角：")
a, b, theta = map(float, x.split())
c = math.sqrt(pow(a,2)+pow(b,2)-2 * a * b * math.cos(theta*math.pi/180))

print(c)
