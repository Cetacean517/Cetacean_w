# arr = []
# while 1:
#     s = input()
#     arr.append(list(map(int, s.split())))
#     if len(arr) == 2: break
#
# n = arr[0][0]
# x = arr[0][1]
# gift = arr[1]
#
# index = [x for x in range(n)]
# num = 0
# for i in range(n):
#     for j in index[i+1:]:
#         print(gift[i], " ,", gift[j])
#         if abs(gift[i]-gift[j]) % 2 == 0:
#             num += 1
# print(num)

# arr = []
# while 1:
#     s = input()
#     arr.append(list(map(int, s.split())))
#     if len(arr) == 2: break
#
# n = arr[0][0]
# x = arr[0][1]
# gift = arr[1]
#
# index = [x for x in range(n)]
# minus = []
# num = 0
# for i in range(n):
#     pos = i+1
#     while pos < n:
#         minus.append(abs(gift[i]-gift[pos]))
#         pos += 1
# for i in minus:
#     if i % x == 0:
#         num += 1
# print(num)

arr = []
while 1:
    s = input()
    arr.append(list(map(int, s.split())))
    if len(arr) == 2: break

n = arr[0][0]
x = arr[0][1]
gift = arr[1]

minus = []
num = 0
gift_r = list(map(lambda y:y%x,gift))
for i in range(x):
    x = gift_r.count(i)
    num += x * (x-1)/2
print(int(num))