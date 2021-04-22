"""可缩减单词："""

import time


def getwords(w):
    """
    :param w: 单词（字符串）
    :return: t1.get(w,-1) 在字典中查找单词w，找到返回对应的value值，否则返回-1.
    """
    if len(w) == 1:  # 只有单词只有一个字母时
        t1[w] = 1
    elif t1.get(w, -1) == 0 and len(w) > 0:  # 单词大于一个字母时
        # minus = [w.replace(w[i], "") for i in range(len(w))]  # 把每一个减少一位的单词存入数组再查找 # 对于apple中，删除p会把两个p同时删除。
        minus = [w[:i] + w[i + 1:] for i in range(len(w))]  # 把每一个减少一位的单词存入数组再查找
        # print(w, '的子单词：', minus)

        # 对于每一个子单词，判断子单词在字典中，继续查找
        for k in minus:
            getwords(k)
            if t1.get(k, -1) > 0:
                t1[k] = len(k)
                t1[w] = len(w)
    return t1.get(w, -1)


with open('words.txt') as f:
    # dict1 = {x.strip() for x in f}
    # t = ['apple', 'split', 'spit', 'pit', 'it','abc','ab','ap','sit']
    # t1 = {x: 0 for x in t}

    start = time.time()
    t = [x.strip() for x in f]
    t1 = {x.strip(): 0 for x in t}
    for i in t:
        getwords(i)
    # print('change dict:', t1)
    for key in max(t1.items(), key=lambda x: x[1]):
        print(key)
    print('Time:', time.time() - start)

'''complecting
11
Time: 1.9192843437194824'''