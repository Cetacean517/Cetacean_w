import time

# 使用+方法，增加list 成员
result = []
start = time.time()
for i in range(10000):
    result = result + [i]
print(len(result), ',', time.time() - start)

# 使用append方法，增加list成员
result = []
start = time.time()
for i in range(10000):
    result.append(i)
print(len(result), ',', time.time() - start)
