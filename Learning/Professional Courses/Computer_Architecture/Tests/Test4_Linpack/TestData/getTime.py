
def Read(Ns, NB, P, Q):
    filename = "-".join([Ns, NB, P, str(Q)]) + ".txt"
    file = open(filename)
    datas = file.readlines()
    flag = 0
    minTime, gflops = 1000000, ""
    for data in datas:
        flag += 1
        if 43 < flag < 47 or flag == 48:
            Output.write(data)
        elif flag == 47:
            item = [i for i in data.split()]
            minTime, gflops = item[5], item[6]
            Output.write(data)
        elif flag > 47 and (flag - 47) % 10 == 0:
            Output.write(data)
            item = [i for i in data.split()]
            print(str(item[5]),end=", ")
            if item[5] < minTime:
                minTime, gflops = item[5], item[6]
    minData = filename + "： minTime:" + str(minTime) + ", gflops:" + gflops + "\n"
    print(minData)
    Output.write(minData)
    file.close()
    return minData


if __name__ == "__main__":
    N = input("Input suffix:")
    script = open("./script"+N+".txt", "r", encoding="utf-8")
    lines = script.readlines()
    Output = open("output" + N + ".txt", "w", encoding="utf-8")
    dataList = []
    for line in lines:
        runlist = [i for i in line.split(" ")]
        Ns, NB, P, Q = runlist[0], runlist[1], runlist[2], int(runlist[3])
        dataList.append(Read(Ns, NB, P, Q))
    for data in dataList:
        Output.write(data)
    script.close()
    Output.close()
