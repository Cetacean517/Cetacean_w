from math import e, log, exp


# # 方法一：exp + ln
# # log():默认自然对数， int(): 向下取整
# class Solution:
#     def mySqrt(self, x: int) -> int:
#         if x == 0:
#             return 0
#         ans = int(exp(1 / 2 * log(x)))
#         if (ans + 1) ** 2 <= x:
#             return ans + 1
#         return ans

# 方法二：二分查找
# Bin 1.0 二分法（有bug)
# class Solution:
#     def mySqrt(self, x):
#         low = 0
#         high = x
#         while low <= high:
#             mid = (low + high) // 2
#             if mid**2 == x:   # 只有完全平方数 9 可以输出结果；需要调整函数出口
#                 return mid
#             if mid**2 < x:
#                 low = mid + 1
#             else:
#                 high = mid - 1

# # 方法二：Bin 2.0 二分法 （通过）
# class Solution:
#     def mySqrt(self, x):
#         low = 0
#         high = x
#         while low <= high:
#             mid = (low + high) // 2
#             if mid ** 2 <= x:
#                 ans = mid  # 只有当mid**2 < x的时候，才能够更新ans的值
#                 low = mid + 1
#             else:
#                 high = mid - 1
#         return ans


# 方法三：牛顿迭代法
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0

        C, x0 = float(x), float(x)
        while True:
            xi = 0.5 * (x0 + C / x0)
            if abs(x0 - xi) < 1e-7:
                break
            x0 = xi

        return int(x0)


if __name__ == '__main__':
    s = Solution()
    print(s.mySqrt(0))
