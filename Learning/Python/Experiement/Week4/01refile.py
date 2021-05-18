def lzh1(strsrc, n):
    strdes = [chr((ord(j) + n) % ord('z')) for j in strsrc]
    return "".join(strdes)


a = "abcde"
print(lzh1(a, 2))


def lzh2(word, warn):
    if warn in word:
        return False
    else:
        return True


a = "abcde"
print(lzh2(a, 'c'))


def lzh3(word, warn):
    a = True
    for j in word:
        if (j not in warn):
            a = False
    return a


a = "abcde"
print(lzh3(a, 'cdf'))


def lzh4(word, warn):
    a = True
    for j in warn:
        if (j not in word):
            a = False
    return a


f = open("words.txt")
r = f.read()
for k in r.split():
    if (lzh4(k, 'aeiou') == True):
        print(k)


def lzh5(word):
    return True if 'e' in word else False


f = open("words.txt")
r = f.read()
count = 0
for k in r.split():
    if lzh5(k) == False:
        count += 1
print(count / len(r.split()) * 100, "%")


def lzh6(word):
    for i in range(0, len(word) - 1):
        if ord(word[i]) > ord(word[i + 1]):
            return False
    return True


f = open("words.txt")
r = f.read()
count = 0
for k in r.split():
    if lzh6(k) == True:
        print(k)
