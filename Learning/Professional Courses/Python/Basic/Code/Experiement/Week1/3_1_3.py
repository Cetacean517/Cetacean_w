# 1.3
s = input('x,y,z=')
x,y,z = s.split(',')
if x > y:
    x,y = y,x
if x > z:
    x,z = z,x
if y > z:
    y,z = z,y
print(x, y, z)

s = input('x,y,z=')
x,y,z = s.split(',')
x,y,z = sorted([x,y,z])
print(x,y,z)