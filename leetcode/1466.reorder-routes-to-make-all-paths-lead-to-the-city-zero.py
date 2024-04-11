# @lcpr-before-debug-begin
from python3problem1466 import *
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=1466 lang=python3
# @lcpr version=30119
#
# [1466] 重新规划路线
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    e, h, ne, w, idx = [0] * 20010, [-1] * 10010, [0] * 20010, [0] * 10010, 0
    def add(self, a: int, b: int, c: int):
        self.e[self.idx] = b
        self.w[self.idx] = c
        self.ne[self.idx] = self.h[a]
        self.h[a] = self.idx
        self.idx += 1
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        for a, b in connections:
            self.add(a, b, 1)
            self.add(b, a, 0)
        q = [0]
        st = [False] * n
        st[0] = True
        res = 0
        while q:
            t = q.pop(0)
            i = self.h[t]
            while i != -1:
                j = self.e[i]
                if not st[j]:
                    st[j] = True
                    res += self.w[i]
                    q.append(j)
                i = self.ne[i]
        return res
# @lc code=end


# @lcpr-div-debug-arg-start
# funName=minReorder
# paramTypes= ["number","number[][]"]
# @lcpr-div-debug-arg-end




#
# @lcpr case=start
# 6\n[[0,1],[1,3],[2,3],[4,0],[4,5]]\n
# @lcpr case=end

# @lcpr case=start
# 5\n[[1,0],[1,2],[3,2],[3,4]]\n
# @lcpr case=end

# @lcpr case=start
# 3\n[[1,0],[2,0]]\n
# @lcpr case=end

#

