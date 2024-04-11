#
# @lc app=leetcode.cn id=128 lang=python3
# @lcpr version=30119
#
# [128] 最长连续序列
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        ans = 0
        for num in nums:
            if num - 1 not in nums:
                res = 1
                while num + 1 in nums:
                    res += 1
                    num += 1
                ans = max(ans, res)
        return ans


# @lc code=end



#
# @lcpr case=start
# [100,4,200,1,3,2]\n
# @lcpr case=end

# @lcpr case=start
# [0,3,7,2,5,8,4,6,0,1]\n
# @lcpr case=end

#

