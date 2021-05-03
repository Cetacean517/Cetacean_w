from collections import Counter
cnt = Counter()
for word in ['red','blue','red','green','blue','blue']:
    cnt[word] += 1
print(cnt)