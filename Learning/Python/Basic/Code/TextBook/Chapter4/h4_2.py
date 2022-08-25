"""1. 假设有一段英文，其中有单独的字母i误写为I，请编写程序进行纠正。"""
import re


def correct1(s):
    print(re.sub(r'\bI\b', 'i', s))  # 利用正则替换


s = input("s: ")
correct1(s)
# s: I am a girl. I. I,
# i am a girl. i. i,
