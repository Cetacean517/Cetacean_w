import time

# 测试：insert插入第一位和append插入最后一位的时间差
# 使用+方法，增加list 成员
def Insert():
    a = []
    for i in range(10000):
        a.insert(0, i)

def Append():
    a = []
    for i in range(10000):
        a.append(i)


start = time.time()
# 做十次
for i in range(10):
    Insert()
print('Insert:', time.time() - start)


start = time.time()
for i in range(10):
    Append()
print('Append:', time.time() - start)

