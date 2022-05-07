#!/usr/bin/python3.9
# @Time    : 2022/5/7 14:13
# @Author  : Cetacean
# @File    : 50_Quick_pow.py

# 快速幂 + 递归
class Solution1:
    def myPow(self, x: float, n: int) -> float:
        def quickMul(N):
            if N == 0:
                return 1.0
            else:
                y = quickMul(N//2)
                return y * y if N % 2 == 0 else y * y * x
        return quickMul(n) if n > 0 else 1/quickMul(-n)


# 快速幂 + 迭代法
# 2 ^ 77 ： （77）2 = 1 + 4 + 8 + 64， 只要求x对应次数的幂即可
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def quickMul(N):
            ans = 1.0
            x_contribute = x                # 贡献的初始值为 x^1
            while N > 0:                    # 在对 N 进行二进制拆分的同时计算答案
                if N % 2 == 1:              # 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                    ans *= x_contribute
                x_contribute *= x_contribute  # 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
                N //= 2
            return ans

        return quickMul(n) if n >= 0 else 1.0 / quickMul(-n)


if __name__ == "__main__":
    s = Solution()
    print(s.myPow(2, 77))
