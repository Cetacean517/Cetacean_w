import time

start = time.time()


# def dfs(s):
#     sub = [s.replace(s[i], "") for i in range(len(s))]
#     max_ = -1
#     for i in [j for j in sub if type(dic.get(j)) == int]:
#         dic[i] = dfs(i) if dic[i] == -1 else dic[i]
#         max_ = dic[i] if dic[i] > max_ else max_
#     dic[s] = max_ + 1
#     return dic[s]


def dfs(s):
    if dic.get(s, 0) == -1:
        sub = [s.replace(s[i], "") for i in range(len(s))]
        dic[s] = max([dfs(i) for i in sub]) + 1
    return dic.get(s, 0)


with open("words.txt", "r") as f:
    dic = {w.strip(): -1 for w in f}
print(max(dic, key=lambda k: dfs(k)))
# [dfs(k) for k in dic.keys()]
# print(max(dic, key=dic.get))
# print(dic)
# print(foo("completing"))
print("dic[sprite]:", dic["sprite"])
print("dic[spite]:", dic["spite"])
print("dic[spit]:", dic["spit"])
print("dic[pit]:", dic["pit"])
print("dic[it]:", dic["it"])
# print("dic[i]:",dic["i"])
# print(dic["aa"])
end = time.time()
print("总用时：", end - start)
# # print(dic)