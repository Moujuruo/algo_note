#
# @lc app=leetcode.cn id=2207 lang=python3
# @lcpr version=30119
#
# [2207] 字符串中最多数目的子序列
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
        ans_1 = 0
        cnt_c = 0
        size = len(text)
        for i in range(size - 1, -1, -1):
            if text[i] == pattern[0]:
                ans_1 += cnt_c
            if text[i] == pattern[1]:
                cnt_c += 1
        ans_1 += cnt_c
                
        ans_2 = 0
        cnt_a = 0
        for i in range(size):
            if text[i] == pattern[1]:
                ans_2 += cnt_a
            if text[i] == pattern[0]:
                cnt_a += 1
        ans_2 += cnt_a
        return max(ans_1, ans_2)

# @lc code=end



#
# @lcpr case=start
# "abdcdbc"\n"ac"\n
# @lcpr case=end

# @lcpr case=start
# "aabb"\n"ab"\n
# @lcpr case=end

#

