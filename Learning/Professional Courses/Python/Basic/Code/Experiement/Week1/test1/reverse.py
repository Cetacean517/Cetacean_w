# 1.	反序对：如果一个单词是另一个单词的反向序列，则称这两个单词为“ 反向对”。编写代码输出 word.txt 中词汇表包含的反向对。
## 版本1.0 速度慢
# with open("D:/Fish 鱼/SHU/Study/Semesters/07 SHU 2nd spring/Python/上机/Python计算实验一/words.txt", 'r') as f:
#     lines = f.readlines()  # 读取全部内容
#     content = [x.strip() for x in lines]
#
#
#     def find(x):
#         for item in x:
#             for m in x:
#                 a = m[::-1]
#                 # if len(item)!=len(m):
#                 #     continue;
#                 if item == a:
#                     print(item, m)
#         return
#
#     def find_up(x):
#         fr = 0;ba = -1;
#         for item in x:
#             for m in x:
#                 if len(item)!=len(m):
#                     continue
#                 while item[fr] == m[ba]:
#                     if fr == len(item) - 1:
#                         print(item,item[::-1])
#                     fr += 1
#                     ba -= 1


with open("D:/Fish 鱼/SHU/Study/Semesters/07 SHU 2nd spring/Python/上机/Python计算实验一/words.txt", 'r') as f:
    lines = f.readlines()  # 读取全部内容
    content = set([x.strip() for x in lines])   # 把原单词存入content集合
    reverse = set([x[::-1] for x in content])   # 把反序的单词存入reverse集合


    def find():
        listd = list(content.intersection(reverse))     # intersection()求集合的交集
        listd.sort()
        for i in listd:
            print(i + " " + i[::-1])                # i[::-1]反向输出
        return listd

# 尝试自己写的查找优化：增加了长度判断，首位字母判断，但效果依旧不加
    # def find_se(x):
    #     for item in x:
    #         for i in x:
    #             # print("origin: " + i)
    #             # print("pare: " + item)
    #             if len(item) != len(i) or item == i:
    #                 continue
    #             elif len(item) == len(i):
    #                 count = 0
    #                 while count < len(item) and item[count] == i[- count - 1]:
    #                     # print(1)
    #                     # print(count)
    #                     # print(item[count] + " " + i[-count-1])
    #                     # print(i + " " + item)
    #                     if (count + 2) != len(item):  # 倒数一位之前都继续比较下一位
    #                         count += 1
    #                         # print(count)
    #                         # print(len(item))
    #                     else:
    #                         # print(count + 2)
    #                         # print(len(item))
    #                         if item[count + 1] == i[- count - 2]:
    #                             print(item + ' ' + i)
    #                             break
    #                 count += 1


    if __name__ == '__main__':
        find()
