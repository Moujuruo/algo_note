#
# @lc app=leetcode.cn id=54 lang=python3
# @lcpr version=30119
#
# [54] 螺旋矩阵
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        
        m, n = len(matrix), len(matrix[0])
        visited = [[False] * n for _ in range(m)]
        self.res = []
        self.dfs(matrix, 0, 0, visited)
        return self.res
    
    def dfs(self, matrix, x, y, visited):
        if x < 0 or x >= len(matrix) or y < 0 or y >= len(matrix[0]) or visited[x][y]:
            return
        
        self.res.append(matrix[x][y])
        visited[x][y] = True
        
        # 右
        self.dfs(matrix, x, y + 1, visited)
        # 下
        self.dfs(matrix, x + 1, y, visited)
        # 左
        self.dfs(matrix, x, y - 1, visited)
        # 上
        self.dfs(matrix, x - 1, y, visited)

# @lc code=end



#
# @lcpr case=start
# [[1,2,3],[4,5,6],[7,8,9]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
# @lcpr case=end

#

