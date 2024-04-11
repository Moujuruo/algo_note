#
# @lc app=leetcode.cn id=518 lang=python3
# @lcpr version=30120
#
# [518] 零钱兑换 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        f = [0] * (amount + 1)
        f[0] = 1    

        for i in range(n):
            for j in range(coins[i], amount + 1):
                f[j] += f[j - coins[i]]
        return f[amount]
# @lc code=end



#
# @lcpr case=start
# 5\n[1, 2, 5]\n
# @lcpr case=end

# @lcpr case=start
# 3\n[2]\n
# @lcpr case=end

# @lcpr case=start
# 10\n[10]\n
# @lcpr case=end

#

