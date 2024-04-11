# @lcpr-before-debug-begin
from python3problem2370 import *
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=2370 lang=python3
# @lcpr version=30119
#
# [2370] 最长理想子序列
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        n = len(s)
        f = [0] * (26)
        for c in s:
            left = max(ord(c) - ord('a') - k, 0)
            right = min(ord(c) - ord('a') + k, 25)
            f[ord(c) - ord('a')] = max(f[left:right + 1]) + 1
        return max(f)

# @lc code=end


# @lcpr-div-debug-arg-start
# funName=longestIdealString
# paramTypes= ["string","number"]
# @lcpr-div-debug-arg-end




#
# @lcpr case=start
# "acfgbd"\n2\n
# @lcpr case=end

# @lcpr case=start
# "abcd"\n3\n
# @lcpr case=end

#

