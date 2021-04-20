import sys

x=input('请按照以下格式输入时间（24小时制）-Hour:Minute:second-(如 19:33:22): ')
if  x[2]!=':' or x[5]!=':':
    print("输入的时间格式有误")
    sys.exit(0)
h,m,s=x.split(':')
hour=int(h)
minute=int(m)
second=int(s)
if hour>23 or second>59 or minute >59 or hour<0 or second<0 or minute<0:
    print("输入的时间格式有误")-1
    sys.exit(1)
second+=1

if second == 60:
    second=0
    minute+=1
if minute == 60:
    minute=0
    hour+=1
if hour == 24:
    hour = 0
if second <=9:
    s='0'+str(second)
else:
    s=str(second)
if minute <=9:
    m='0'+str(minute)
else:
    m=str(minute)
if hour<=9:
    h='0'+str(hour)
else:
    h=str(hour)

print(h+":"+m+":"+s)