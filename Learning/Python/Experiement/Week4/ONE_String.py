def rotateword(strsrc, n):
    strdes = [chr((ord(j) + n) % ord('z')) for j in strsrc]
    return "".join(strdes)


# 1.1
a = "abcde"
print(rotateword(a, 2))


def avoids(word, warn):
    if warn in word:
        return False
    else:
        return True


# 1.2 判断字符串中是否含有禁止单词
a = "abcde"
print(avoids(a, 'c'))


def useonly(word, warn):
    a = True
    for j in word:
        if j not in warn:
            a = False
    return a


a = "abcde"
print(useonly(a, 'cdf'))


# print(useonly('cdcdffd', 'cdf'))


def useall(word, warn):
    a = True
    for j in warn:
        if j not in word:
            a = False
    return a


f = open("words.txt")
r = f.read()
for k in r.split():
    if useall(k, 'aeiou'):
        print(k)


def hasnoe(word):
    return True if 'e' in word else False


f = open("words.txt")
r = f.read()
count = 0
for k in r.split():
    if not hasnoe(k):
        count += 1
print(count / len(r.split()) * 100, "%")


def iasbecedarian(word):
    for i in range(0, len(word) - 1):
        if ord(word[i]) > ord(word[i + 1]):
            return False
    return True


f = open("words.txt")
r = f.read()
count = 0
for k in r.split():
    if iasbecedarian(k):
        print(k)
