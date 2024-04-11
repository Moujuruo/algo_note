#
# @lc app=leetcode.cn id=2789 lang=python3
# @lcpr version=30119
#
# [2789] 合并后数组中的最大元素
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        len = nums.__len__()
        res = nums[-1]
        ans = -0x3f
        for i in range(len - 2, -1, -1):
            if nums[i] <= res:
                res = res + nums[i]
            else:
                res = nums[i]
            ans = max(ans, res)
            
        return max(ans, res)
# @lc code=end


# @lcpr-div-debug-arg-start
# funName=[77]
# paramTypes= ["number[]"]
# @lcpr-div-debug-arg-end




#
# @lcpr case=start
# [2,3,7,9,3]\n
# @lcpr case=end

# @lcpr case=start
# [5,3,3]\n
# @lcpr case=end

#

