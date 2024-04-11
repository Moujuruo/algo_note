#
# @lc app=leetcode.cn id=1008 lang=python3
# @lcpr version=30119
#
# [1008] 前序遍历构造二叉搜索树
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
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return None
        root = TreeNode(preorder[0])
        i = 1
        while i < len(preorder) and preorder[i] < root.val:
            i += 1
        root.left = self.bstFromPreorder(preorder[1:i])
        root.right = self.bstFromPreorder(preorder[i:])
        return root
# @lc code=end



#
# @lcpr case=start
# [8,5,1,7,10,12]\n
# @lcpr case=end

# @lcpr case=start
# [1,3]\n
# @lcpr case=end

#

