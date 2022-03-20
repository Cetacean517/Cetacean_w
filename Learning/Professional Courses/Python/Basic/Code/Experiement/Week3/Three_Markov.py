from urllib.request import urlopen
from random import randint


def wordListSum(wordList):
    # 求取某个单词中所有后缀出现次数总和，用于随机选择下一个出现的单词
    sum1 = 0
    for word, value in wordList.items():
        sum1 += value
    return sum1


def retrieveRandomWord(wordList):
    # 用于选择生成下一个出现的单词
    randIndex = randint(1, wordListSum(wordList))
    for word, value in wordList.items():
        randIndex -= value
        if randIndex <= 0:
            return word


def buildWordDict(text):
    # 剔除换行符和引号
    text = text.replace("\n", " ")
    text = text.replace("\"", "")
    text = text.replace("--", "")
    # 保证每个标点符号都和前面的单词在一起
    # 这样不会被剔除，保留在马尔科夫链中
    punctuation = [',', '.', ';', ':']
    for symbol in punctuation:
        text = text.replace(symbol, " " + symbol + " ")
    words = text.split(" ")
    # 过滤空单词
    words = [word for word in words if word != ""]

    wordDict = {}
    for i in range(1, len(words)):
        if words[i - 1] not in wordDict:
            # 为单词新建一个字典
            wordDict[words[i - 1]] = {}
        if words[i] not in wordDict[words[i - 1]]:
            wordDict[words[i - 1]][words[i]] = 0
        wordDict[words[i - 1]][words[i]] = wordDict[words[i - 1]][words[i]] + 1
    return wordDict


# text = str('Today is a good day! I love summer!! Today is a bad day.')
text = open('emma.txt', 'r').read()
wordDict = buildWordDict(text)
# 生成链长为length的马尔科夫链
length = 40
# 句子个数为m句
m = 4
chain = ""
currentWord = "I"
for i in range(0, m):
    chain = ''
    for j in range(0, length // m):
        chain += str(currentWord + ' ')
        # 将每句开头设置为大写
        if j == 0:
            chain = chain.replace(chain[0], chain[0].upper())
        currentWord = retrieveRandomWord(wordDict[currentWord])
    chain += str('.')
    print(chain)