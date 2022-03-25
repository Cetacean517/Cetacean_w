from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        low, high = 0, target
        ans = List[int]
        while low <= high:
            mid = (low + high) // 2
            if List[mid] < target:
                mid = high + 1
            elif List[mid] > target:
                mid = low + 1
            else:
                pass

