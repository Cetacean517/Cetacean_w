# 适合打劫的日子
from typing import List


class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        date = [-len(security)] * len(security)
        temp = security[0]
        pos = 0
        for data in security:
            if data >= time:
                date[pos] = 0
                if data > temp:
                    date[pos] += 1
                elif data < temp:
                    date[pos] -= 1
                pos += 1
        pos = 0
        # for i in range

        print(date)

class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        left = [0] * n
        right = [0] * n
        for i in range(1, n):
            if security[i] <= security[i - 1]:
                left[i] = left[i - 1] + 1
            if security[n - i - 1] <= security[n - i]:
                right[n - i - 1] = right[n - i] + 1
        return [i for i in range(time, n - time) if left[i] >= time and right[i] >= time]


if __name__ == "__main__":
    security = [5, 3, 3, 5, 6, 2]
    time = 2
    s = Solution()
    s.goodDaysToRobBank(security, time)
