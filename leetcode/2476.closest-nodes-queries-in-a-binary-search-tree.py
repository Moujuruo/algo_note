# @lcpr-before-debug-begin
from python3problem2476 import *
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=2476 lang=python3
# @lcpr version=30119
#
# [2476] 二叉搜索树最近节点查询
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    nodes = []
    def closestNodes(self, root: Optional[TreeNode], queries: List[int]) -> List[List[int]]:

        def dfs(node: Optional[TreeNode]):
            if node is None:
                return
            dfs(node.left)
            self.nodes.append(node.val)
            dfs(node.right)
        dfs(root)

        def binary_find_max_smaller(x: int):
            l, r = 0, len(self.nodes) - 1
            while l < r:
                mid = (l + r + 1) // 2
                if self.nodes[mid] <= x:
                    l = mid
                else:
                    r = mid - 1
            return l
        
        def binary_find_min_larger(x: int):
            l, r = 0, len(self.nodes) - 1
            while l < r:
                mid = (l + r) // 2
                if self.nodes[mid] >= x:
                    r = mid
                else:
                    l = mid + 1
            return l
        
        res = []
        res.append(self.nodes)

        for q in queries:
            temp = []
            max_smaller = binary_find_max_smaller(q)
            min_larger = binary_find_min_larger(q)
            if self.nodes[max_smaller] > q or max_smaller < 0:
                temp.append(-1)
            else:
                temp.append(self.nodes[max_smaller])
            if self.nodes[min_larger] < q or min_larger >= len(self.nodes):
                temp.append(-1)
            else:
                temp.append(self.nodes[min_larger])
            res.append(temp)
            
        return res
                
# @lc code=end


# @lcpr-div-debug-arg-start
# funName=[4,null,9]\n[3]
# paramTypes= ["number[]","number[]"]
# @lcpr-div-debug-arg-end




#
# @lcpr case=start
# [6,2,13,1,4,9,15,null,null,null,null,null,null,14]\n[2,5,16]\n
# @lcpr case=end

# @lcpr case=start
# [4,null,9]\n[3]\n
# @lcpr case=end

#

