import math

arr = []
while 1:
    s = input()
    if s!='':
        arr = list(map(int, s.split()))
    else:
        break
    m = arr[0]
    n = arr[1]
    if m > n : print("no")
    else:
        flag = False
        num = [m + x for x in range(n-m+1)]
        for N in num:
            g = N % 10
            s = ((N - g)//10) % 10
            b = N // 100
            if N == g**3 + s**3 + b**3:
                flag = True
                print(N,end=' ')
        if not flag:
            print("no")
        print('\n')
