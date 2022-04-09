from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        low, high = 0, len(nums) - 1
        pos = -1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] < target:
                low = mid + 1
            elif nums[mid] > target:
                high = mid - 1
            else:
                pos = mid
                break
        if pos == -1:
            return [-1, -1]
        else:
            begin = end = pos
            while (begin - 1) > -1 and nums[begin - 1] == target:
                begin -= 1
            while (end + 1) < len(nums) and nums[end + 1] == target:
                end += 1
        return [begin, end]


if __name__ == "__main__":
    s = Solution()
    # nList = [5, 7, 7, 8, 8, 10]
    test1 = [1,1,2]

    print(s.searchRange(test1, 1))
