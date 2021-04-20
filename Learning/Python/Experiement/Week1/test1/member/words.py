# -- coding:utf-8 --
f = open("D:/Fish 鱼/SHU/Study/Semesters/07 SHU 2nd spring/Python/上机/Python计算实验一/words.txt","r")

listb = []
listc = []
for line in f.readlines():
    line = line.strip()

    listb.append(line)
    listc.append(line[::-1])


listd=list(set(listb).intersection(set(listc)))
listd.sort()
for i in listd:
    print (i)

"""for i in listb:
    for j in listb:
        if i == j[::-1] and listb.index(i) <= listb.index(i[::-1]):
            print(str(i)+"-"+str(j))"""






f.close()