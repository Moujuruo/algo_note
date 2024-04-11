#
# @lc app=leetcode.cn id=1123 lang=python3
# @lcpr version=30119
#
# [1123] 最深叶节点的最近公共祖先
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
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        ans = None
        maxDepth = -1

        def dfs(node: Optional[TreeNode], depth: int) -> int:
            nonlocal ans, maxDepth
            if node is None:
                maxDepth = max(depth, maxDepth)
                return depth
            left = dfs(node.left, depth + 1)
            right = dfs(node.right, depth + 1)
            if maxDepth == left and left == right:
                ans = node
            return max(left, right)
        
        dfs(root, 0)
        return ans
# @lc code=end



#
# @lcpr case=start
# [3,5,1,6,2,0,8,null,null,7,4]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,3,null,2]\n
# @lcpr case=end

#

