def make_words_dict():
    d = dict()
    fin = open('words.txt')
    # fin = open('test.txt')
    for line in fin:
        word = line.strip().lower()  # 移除字符串头尾指定的字符
        d[word] = word
    for x in ['a', 'i', '']:  # a,i,空字符串都算作单词
        d[x] = x
    return d


record = {}
record[''] = ['']


def iscuttable(word, word_dict):  # 看这一个单词是否可缩减
    if word in record:  # 跳出递归
        return record[word]
    list = []  # 需要用record保存，否则list在每次递归时被清空
    for suo in suojian(word, word_dict):
        x = iscuttable(suo, word_dict)  # 递归看再缩减的情况
        if x:
            list.append(suo)
    record[word] = list
    return list


def suojian(word, word_dict):  # 找每个单词缩减一个字母且在单词表的列表
    list = []
    for i in range(len(word)):
        x = word[:i] + word[i + 1:]
        if x in word_dict:
            list.append(x)
    return list


if __name__ == '__main__':
    word_dict = make_words_dict()
    list = []
    for word in word_dict:
        x = iscuttable(word, word_dict)
        if x:
            list.append(word)
    # print(list)
    longest = max(list, key=len, default="")
    print(longest)