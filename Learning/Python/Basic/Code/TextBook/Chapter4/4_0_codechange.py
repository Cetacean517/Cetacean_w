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
        # result = result + chr(ord(ch) + key)
        result = result + chr(ord(ch) ^ ord(next(temp)))
    return result

def clist(str):
    return []

# source = 'ABCDEFG0123456'
key = '1'
#
# print('Before:' + source)
# encrypted = crypt(source, key)
# print('After En:' + encrypted)
# decrypted = crypt(encrypted, key)
# print('After De:' + decrypted)

m = 'D9B1D2C7DAD3D0DFA4C6DADAA3ACA3BDD9DB'
n = 'DAB2D1C4D9D0D3DCA0C5D9D9A0AFA0BEDAE9'
k = 'DBB3D0C5D8D1D2DDA0C4D8D8A1AEA1BFDBE7'

m0=m[1::2]
n0=n[1::2]
print(m0)
print(n0)
m1 = (int(m0,16))
n1 = (int(n0,16))
print(m1)
print(n1)
print(n1-m1)

# for i in range(10):
#     # print("偏移" + str(i) + "位：")
#     # print(crypt(m, i))
#     m_new = set(crypt(m, ))
#     for j in range(10):
#         n_new = set(crypt(m, str(j)))
#         dif = n_new ^ m_new
#         if dif:
#             print(str(i) + '位' + str(j) + '列:')
#             print(dif)
#         k_new = set(crypt(m, i))
