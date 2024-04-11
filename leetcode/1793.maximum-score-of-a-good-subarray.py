#
# @lc app=leetcode.cn id=1793 lang=python3
# @lcpr version=30119
#
# [1793] 好子数组的最大分数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left = [0] * n
        right = [0] * n
        stack = []
        for i in range(n):
            while stack and nums[stack[-1]] >= nums[i]:
                stack.pop()
            left[i] = stack[-1] if stack else -1
            stack.append(i)
        stack = []
        for i in range(n - 1, -1, -1):
            while stack and nums[stack[-1]] >= nums[i]:
                stack.pop()
            right[i] = stack[-1] if stack else n
            stack.append(i)

        res = 0
        for i in range(n):
            if left[i] < k < right[i]:
                res = max(res, nums[i] * (right[i] - left[i] - 1))
        return res
# @lc code=end



#
# @lcpr case=start
# [1,4,3,7,4,5]\n3\n
# @lcpr case=end

# @lcpr case=start
# [5,5,4,5,4,1,1,1]\n0\n
# @lcpr case=end

#

