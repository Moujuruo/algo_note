#
# @lc app=leetcode.cn id=1664 lang=python3
# @lcpr version=30119
#
# [1664] 生成平衡数组的方案数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        odd = 0
        even = 0
        for i, num in enumerate(nums):
            if i % 2 == 0:
                even += num
            else:
                odd += num
        ans = 0
        tot_odd = 0
        tot_even = 0
        for i in range(len(nums)):
            if i % 2 == 0:
                tot_even = tot_even + nums[i]
            else:
                tot_odd = tot_odd + nums[i]
            if i % 2 == 1:
                if even - tot_even + tot_odd - nums[i] == odd - tot_odd + tot_even:
                    ans += 1
            else:
                if even - tot_even + tot_odd == odd - tot_odd + tot_even - nums[i]:
                    ans += 1
        return ans
            
# @lc code=end



#
# @lcpr case=start
# [2,1,6,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,1,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

#

