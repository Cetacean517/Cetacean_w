# 763. 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
from typing import List


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last = [0] * 26
        for i, ch in enumerate(s):      # 每个字母一个位置，记录改字母最后一次出现的位置
            last[ord(ch) - ord("a")] = i

        partition = list()
        start = end = 0
        for i, ch in enumerate(s):
            # 寻找结束最大的情况
            # 当前字母和这段字符的最大位置一致的时候，这个片段结束。
            end = max(end, last[ord(ch) - ord("a")])
            if i == end:
                partition.append(end - start + 1)
                start = end + 1

        return partition




if __name__ == "__main__":
    S = "eccbbbbdec"
    a = Solution()
    a.partitionLabels(S)
