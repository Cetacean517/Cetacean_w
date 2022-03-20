def sumNumber():
    a = '15' * 10
    b = '3' * 20
    sum1 = 0
    m = int(a) * int(b)
    total = str(m)
    for i in range(0, len(str(total))):
        sum1 += int(total[i])
    print(sum1)

def sumMuliply():
    sum = 1
    for i in range(0,2015):
        sum *= 2016
    print(sum)

print("输出15...15(10个15)× 33...3(20个3)的结果："+'/n')
sumNumber()
print("输出2016个2016相乘的结果")
sumMuliply()
