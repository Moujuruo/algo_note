#
# @lc app=leetcode.cn id=2684 lang=python3
# @lcpr version=30119
#
# [2684] 矩阵中移动的最大次数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from collections import deque


class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        Vis = [[False] * m for _ in range(n)]
        q = deque()
        for i in range(n):
            q.append((i, 0))
            Vis[i][0] = True
        ans = 0
        while q:
            t = q.popleft()
            x, y = t
            ans = max(ans, y)
            c = y + 1
            if c == m:
                break
            for r in [x - 1, x, x + 1]:
                if r < 0 or r >= n:
                    continue
                if Vis[r][c]:
                    continue
                if grid[r][c] > grid[x][y]:
                    q.append((r, c))
                    Vis[r][c] = True
                    flag = True
                    
        return ans

# @lc code=end



#
# @lcpr case=start
# [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]\n
# @lcpr case=end

# @lcpr case=start
# [[3,2,4],[2,1,9],[1,1,7]]\n
# @lcpr case=end

#

