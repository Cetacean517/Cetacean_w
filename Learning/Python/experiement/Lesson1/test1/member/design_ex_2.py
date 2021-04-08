x=input('请按照以下格式输入时间（24小时制）-Hour:Minute:second-(如 19:33:22): ')
h,m,s=x.split(':')
hour=int(h)
minute=int(m)
second=int(s)
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