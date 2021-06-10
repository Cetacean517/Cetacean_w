# s1 = '中国'
# print(s1)
#
# print(len(s1))
#
# s2 = s1.decode('GBK')
# print(s2)


# def crypt(source, key):
#     from itertools import cycle
#     result = ''
#     temp = cycle(key)
#     for ch in source:
#         result = result + chr(ord(ch) ^ ord(next(temp)))
#     return result
#
#
# source = 'Shandong Institute of Business and Technology'
# key = 'BCDEF'
#
# print('Before:' + source)
# encrypted = crypt(source, key)
# print('After En:' + encrypted)
# decrypted = crypt(encrypted, key)
# print('After De:' + decrypted)


def crypt(source, key):
    from itertools import cycle
    result = ''
    temp = cycle(key)
    for ch in source:
        result = result + chr(ord(ch) + 1)
    return result


source = 'ABCDEFG0123456'
key = '1'

print('Before:' + source)
encrypted = crypt(source, key)
print('After En:' + encrypted)
decrypted = crypt(encrypted, key)
print('After De:' + decrypted)

