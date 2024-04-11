#
# @lc app=leetcode.cn id=310 lang=python3
# @lcpr version=30119
#
# [310] 最小高度树
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from collections import deque


class Solution:
    def add(self, graph, u, v):
        graph[u].append(v)
        graph[v].append(u)
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        graph = [[] for _ in range(n)]
        cnt = [0] * n
        for u, v in edges:
            self.add(graph, u, v)
            cnt[u] += 1
            cnt[v] += 1
        q = deque()
        for i in range(n):
            if cnt[i] == 1:
                q.append(i)

        while n > 2:
            size = len(q)
            n -= size
            for _ in range(size):
                u = q.popleft()
                for v in graph[u]:
                    cnt[v] -= 1
                    if cnt[v] == 1:
                        q.append(v)
        return list(q)
# @lc code=end



#
# @lcpr case=start
# 4\n[[1,0],[1,2],[1,3]]\n
# @lcpr case=end

# @lcpr case=start
# 6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]\n
# @lcpr case=end

#

