# 1-2
import math

x = input("请输入三角形的两条边及其夹角（度）：")
a,b,theta = map(float,x.split())       # 序列解包
c = math.sqrt(a**2+b**2-2*a*b*math.cos(theta*math.pi/180))
print("c=",c)