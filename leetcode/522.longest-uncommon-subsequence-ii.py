# @lcpr-before-debug-begin
from python3problem522 import *
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=522 lang=python3
# @lcpr version=30119
#
# [522] 最长特殊序列 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def Check(self, a: str, b: str) -> bool:
        if len(a) > len(b):
            return False
        pa, pb = 0, 0
        while pa < len(a) and pb < len(b):
            if a[pa] == b[pb]:
                pa += 1
            pb += 1
        return pa == len(a)


    def findLUSlength(self, strs: List[str]) -> int:
        sorted_strs = sorted(strs, key=lambda x: len(x), reverse=True)
        n = len(sorted_strs)        
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if self.Check(sorted_strs[i], sorted_strs[j]):
                    break
            else:
                return len(sorted_strs[i])
            
        return -1
# @lc code=end



#
# @lcpr case=start
# ["aba","cdc","eae"]\n
# @lcpr case=end

# @lcpr case=start
# ["aaa","aaa","aa"]\n
# @lcpr case=end

#

