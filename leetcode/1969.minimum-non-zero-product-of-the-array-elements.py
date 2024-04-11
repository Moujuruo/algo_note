#
# @lc app=leetcode.cn id=1969 lang=python3
# @lcpr version=30119
#
# [1969] 数组元素的最小非零乘积
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    mod = 10 ** 9 + 7

    def pow(self, x, y, mod):
        if y == 0:
            return 1
        if y % 2 == 0:
            return self.pow(x * x % mod, y // 2, mod)
        else:
            return x * self.pow(x, y - 1, mod) % mod
    def minNonZeroProduct(self, p: int) -> int:
        k = 2 ** p - 1
        return (self.pow(k - 1, k // 2, self.mod) * k) % self.mod

# @lc code=end



#
# @lcpr case=start
# 1\n
# @lcpr case=end

# @lcpr case=start
# 2\n
# @lcpr case=end

# @lcpr case=start
# 3\n
# @lcpr case=end

#

