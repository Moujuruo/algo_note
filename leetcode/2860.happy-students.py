# @lcpr-before-debug-begin
from python3problem2860 import *
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=2860 lang=python3
# @lcpr version=30119
#
# [2860] 让所有学生保持开心的分组方法数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def countWays(self, nums: List[int]) -> int:
        # 0 2 3 3 6 6 7 7
        n = len(nums)
        nums.sort()
        ans = 0
        selected = 0
        if selected < nums[0]:
            ans += 1

        for i in range(n):
            if selected < nums[i] and i > 0 and selected > nums[i - 1]:
                ans += 1
            selected += 1
        if selected >= nums[-1]:
            ans += 1

        return ans
            
# @lc code=end


# @lcpr-div-debug-arg-start
# funName=countWays
# paramTypes= ["number[]"]
# @lcpr-div-debug-arg-end




#
# @lcpr case=start
# [1,1]\n
# @lcpr case=end

# @lcpr case=start
# [6,0,3,3,6,7,2,7]\n
# @lcpr case=end

#

