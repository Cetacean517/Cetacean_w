#!/usr/bin/env python
# -*-coding:utf-8-*-
# @Time: 4/13/2021 5:19 PM
# @File: keywords.py
# @Author: Chasing
# @Email: chasing1020@gmail.com
# @Software: PyCharm


import jieba.analyse
import reply
import query


def getKeyWord(sentence):
    type = jieba.analyse.extract_tags(sentence, topK=3)[0]
    return type


print(getKeyWord("""颈椎不好的病人多数表现在颈部的疼痛僵硬，这时候应该注意改变自己的生活方式。不要枕比较高的枕头，不要长期低头玩手机工作，建议适当活动颈椎，可以打羽毛球、游泳等活动。如果出现了上肢的麻木疼痛，或者下肢的无力等症状，说明颈椎有突出的情况，压迫周围的神经。建议到医院骨科做颈椎的CT，看颈椎压迫神经的情况，决定是否手术治疗，如果手术治疗效果还是不错。
"""))