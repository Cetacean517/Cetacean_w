# 第一题
def solution1(A):
    d = {x: A.count(x) for x in A}
    sum = 0
    for kv in d.items():
        sum += min(kv[1], abs(kv[1] - kv[0]))
    return sum

# 第二题

def solution(A):
    A = ["039", "4", "14", "32", "", "34", "7"]
    A = ["801234567", '180234567', "0", "189234567", "891234567","98", "9"]
    day = [[eval(x) for x in A[i]] for i in range(len(A))]
    arr = [[0 for x in range(7)]for m in range(10)]
    for i in range(10): # 10 day
        for j in range(7): # 7 people
            if day[j].count(i):
                arr[i][j] = 1
    day1 = 0
    day2 = 1
    max = arr[0].count(1)
    print(arr)
    print(max)
    for i in range(10):
        out = arr[i]
        if max < 7:
            maxs = max
        else:
            return max
        for j in range(10):
            print("outj ", end='')
            print(j)
            max0 = maxs
            for flag in range(7):
                if arr[i][flag] != 1 and arr[j][flag] == 1:
                    print(arr[i])
                    print(arr[j])
                    print(arr[i][flag])
                    print(arr[j][flag])
                    print(flag)
                    max0 += 1
            print(i,end=":")
            print(j,end=":")
            print(max0)
            if max0 > max:
                max = max0
    print(max0)


    # day= []
    # sum = 0;
    # for i in range(len(A)):
    #     day_i = [eval(x) for x in A[i]]
    #     day.extend(day_i)
    # arrange = {x: day.count(x) for x in day}
    # arr_sort = {k:v for k,v in sorted(arrange.items(),key = lambda item:item[1])}
    # dmax1,num1 = arr_sort.popitem()
    # dmax2,num2 = arr_sort.popitem()
    # sum = num1 + num2
    # for i in range(len(A)):
    #     if str(dmax1) in A[i] and str(dmax2) in A[i]:
    #         print(A[i])
    #         sum -= 1
    # return sum


if __name__ == "__main__":
    solution(0)
    # print(solution(0))
