# @lcpr-before-debug-begin
from python3problem2312 import *
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=2312 lang=python3
# @lcpr version=30119
#
# [2312] 卖木头块
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
        map = [[-1] * (n + 1) for _ in range(m + 1)]
        pr = {(h, w): p for h, w, p in prices}

        def Cal(h, w):
            if map[h][w] != -1:
                return map[h][w]
            r = pr.get((h, w), 0)
            for i in range(1, h // 2 + 1):
                tr = Cal(i, w) + Cal(h - i, w)
                if r < tr:
                    r = tr
            for i in range(1, w // 2 + 1):
                tc  = Cal(h, i) + Cal(h, w - i)
                if r < tc:
                    r = tc
            map[h][w] = r
            return map[h][w]
        return Cal(m, n)


# @lc code=end


# @lcpr-div-debug-arg-start
# funName=sellingWood
# paramTypes= ["number","number","number[][]"]
# @lcpr-div-debug-arg-end




#
# @lcpr case=start
# 3\n5\n[[1,4,2],[2,2,7],[2,1,3]]\n
# @lcpr case=end

# @lcpr case=start
# 4\n6\n[[3,2,10],[1,4,2],[4,1,3]]\n
# @lcpr case=end

#

