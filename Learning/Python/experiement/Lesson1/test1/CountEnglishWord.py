def getTxt():  # 对文本进行如处理
    # 读取文件，返回str
    txt = open("D:/Fish 鱼/SHU/Study/Semesters/07 SHU 2nd spring/Python/上机/Python计算实验一/example/text.txt",
               encoding='UTF-8').read().strip()
    txt = txt.lower()  # 把所有单词都转换成小写
    for ch in ",.!、!@#$%^'":  # 将所有除单词以外的符号换成空格
        txt.replace(ch, '')
    return txt


# 分析提取单词 txtArr是列表
txtArr = getTxt().split(" ")


def keyCount(txt, x):
    count1 = 0
    for item in txt:
        if item == x:
            count1 += 1
    return count1 / len(txt)

# test测试
keyword = input("请输入一个单词")
print(keyCount(txtArr, keyword))

# 单词计数字典
counts = {}  # 创建字典counts.
for word in txtArr:
    counts[word] = counts.get(word, 0) + 1  # 如果字典中没有这个word，则返回0，再+1；否则，取回value,再+1

# 将字典转换为列表
countsList = list(counts.items())
countsList.sort(key=lambda x: x[1], reverse=True)  # 使用lambda匿名函数，对x[1]：按照第二个元素进行排序

# 输出TOP(20)
for i in range(20):
    word, count = countsList[i]
    print('{0:<20}{1:>10}'.format(word, count))
