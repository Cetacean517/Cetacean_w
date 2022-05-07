arr = []
while 1:
    s = input()
    arr.append(list(map(int, s.split())))
    if len(arr) == 2: break

num = arr[0][0]
high = arr[1]
high = sorted(high) # 按升序排列
single = high[0:num:2]
odd = high[1:num:2]
out = 0
for i in range(len(single)):
    if i+1 < len(single):
        sub = single[i+1] - single[i]
        if sub > out:
            out = sub
for i in range(len(odd)):
    if i+1 < len(odd):
        sub = odd[i+1] - odd[i]
        if sub > out:
            out = sub
if high[1] - high[0] > out:
    out = high[1] - high[0]
print(out)