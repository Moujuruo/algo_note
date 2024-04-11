# @lcpr-before-debug-begin
from python3problem1839 import *
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=1839 lang=python3
# @lcpr version=30119
#
# [1839] 所有元音按顺序排布的最长子字符串
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        i = 0
        ans = 0
        dic = ['a', 'e', 'i', 'o', 'u']
        n = len(word)
        cnt = 0
        p = 0
        while i < n:
            if p < 5 and word[i] == dic[p]:
                p += 1
                cnt += 1
            else:
                if p > 0 and p <= 5 and word[i] == dic[p - 1]:
                    cnt += 1
                else:
                    if p != 5:
                       if cnt != 0:
                            i -= 1
                           
                       cnt = 0
                       p = 0
                    else:
                        ans = max(ans, cnt)
                        p = 0
                        cnt = 0
                        i -= 1
            i += 1
        if p == 5:
            ans = max(ans, cnt)
        return ans
                    
                    


# @lc code=end


# @lcpr-div-debug-arg-start
# funName=longestBeautifulSubstring
# paramTypes= ["string"]
# @lcpr-div-debug-arg-end




#
# @lcpr case=start
# "aeiaaioaaaaeiiiiouuuooaauuaeiu"\n
# @lcpr case=end

# @lcpr case=start
# "aeeeiiiioooauuuaeiou"\n
# @lcpr case=end

# @lcpr case=start
# "a"\n
# @lcpr case=end

#

