import string
import re


# '''代码版本2.0 利用正则表达式修改原来的匹配方式，可以使单词匹配更为精准。
def get_dict_word_times():
    # 构建字典{单词: 次数}
    with open("D:/Fish 鱼/SHU/Study/Semesters/07 SHU 2nd spring/Python/上机/Python计算实验一/example/text.txt", 'r',
              encoding='UTF-8')as f:
        content = ''
        for line in f.readlines():
            content = content + line.lower()  # 全部变成小写, 没有去除换行， 但是之后使用正则匹配，不会出现符号问题。

        #    用正则匹配 \b表示英文字母开始和结束 \w+表示多个英文字符,返回list类型数据
        list_word = re.findall(r'\b\w+\b', content)

        # 去掉重复单词, 利用集合去除list中重复的单词
        set_word = set(list_word)

        # 返回每个再集合中的单词，再文中出现的次数 是一个字典
        return {word: list_word.count(word) for word in set_word}


def keyCount(x):
    # 代码版本1.0 最初的计数方式：匹配+简单计数器。
    # # 构建字典{单词: 次数}
    # with open("D:/Fish 鱼/SHU/Study/Semesters/07 SHU 2nd spring/Python/上机/Python计算实验一/example/text.txt", 'r',
    #           encoding='UTF-8')as f:
    #     content = ''
    #     for line in f.readlines():
    #         content = content + line.lower()  # 全部变成小写, 没有去除换行， 但是之后使用正则匹配，不会出现符号问题。
    #
    #     #    用正则匹配 \b表示英文字母开始和结束 \w+表示多个英文字符,返回list类型数据
    #     list_word = re.findall(r'\b\w+\b', content)
    #
    #     # '''最初的计数方式：匹配+简单计数器。
    #     count1 = 0
    #     for item in list_word:
    #         if item == x:
    #             count1 = count1 + 1
    #
    #
    #     print("总单词数为：" + str(len(list_word)) + " " + x + " 有 " + str(count1) + " 个 ")
    #     return count1 / len(list_word)

    # 代码版本2.0：利用字典按照key查找的方式优化算法。
    # 构建字典{单词: 次数}
    with open("D:/Fish 鱼/SHU/Study/Semesters/07 SHU 2nd spring/Python/上机/Python计算实验一/example/text.txt", 'r',
              encoding='UTF-8')as f:
        content = ''
        for line in f.readlines():
            content = content + line.lower()  # 全部变成小写, 没有去除换行， 但是之后使用正则匹配，不会出现符号问题。

        #    用正则匹配 \b表示英文字母开始和结束 \w+表示多个英文字符,返回list类型数据
        list_word = re.findall(r'\b\w+\b', content)

        # 去掉重复单词, 利用集合去除list中重复的单词
        set_word = set(list_word)

        dict_word = {word: list_word.count(word) for word in set_word}
        count1 = dict_word[str(x)]

        print("总单词数为：" + str(len(list_word)) + " list_word" + x + " 有 " + str(count1) + " 个 ")
        return count1 / len(list_word)


def main():
    dict_word_times = get_dict_word_times()

    # 把单词按照次数由多到少排序
    list_sorted_words = sorted(dict_word_times, key=lambda w: dict_word_times[w], reverse=True)
    for word in list_sorted_words:
        print("{} -- {} times".format(word, dict_word_times[word]))

    # test测试
    while 1:
        keyword = input("请输入一个单词：")
        print(keyCount(keyword))


main()

# '''代码版本1.0 问题：利用剔除特殊标点符号的方法，但是仍然会有特殊标点 无法识别剔除，例如：/n /t 等等转移符号。
# def getTxt():  # 对文本进行如处理
#     # 读取文件，返回str
#     txt = open("D:/Fish 鱼/SHU/Study/Semesters/07 SHU 2nd spring/Python/上机/Python计算实验一/example/text.txt",
#                encoding='UTF-8').read().strip()
#     txt = txt.lower()  # 把所有单词都转换成小写
#     for ch in ",.!、!@#$%^';\n":  # 将所有除单词以外的符号换成空格
#         txt.replace(ch, '')
#     return txt
#
#
# # 分析提取单词 txtArr是列表
# txtArr = getTxt().split(" ")
#
#
# def keyCount(txt, x):
#     count1 = 0
#     for item in txt:
#         if item == x:
#             count1 = count1 + 1
#     return count1 / len(txt)
#
#
# print(txtArr)
#
# # test测试
# keyword = input("请输入一个单词")
# print(keyCount(txtArr, keyword))
#
# # # 单词计数字典
# # counts = {}  # 创建字典counts.
# # for word in txtArr:
# #     counts[word] = counts.get(word, 0) + 1  # 如果字典中没有这个word，则返回0，再+1；否则，取回value,再+1
#
# # 将字典转换为列表
# countsList = list(counts.items())
# countsList.sort(key=lambda x: x[1], reverse=True)  # 使用lambda匿名函数，对x[1]：按照第二个元素进行排序
#
# # 输出TOP(20)
# for i in range(20):
#     word, count = countsList[i]
#     print('{0:<20}{1:>10}'.format(word, count))
