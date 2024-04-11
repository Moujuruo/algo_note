#
# @lc app=leetcode.cn id=930 lang=python3
# @lcpr version=30119
#
# [930] 和相同的二元子数组
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from collections import defaultdict


class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        n = len(nums)
        presum = [0] * (n + 1)
        for i in range(1, n + 1):
            presum[i] = presum[i - 1] + nums[i - 1]
        cnt = defaultdict(int, {0: 1})
        ans = 0
        for i in range(1, n + 1):
            ans += cnt[presum[i] - goal]
            cnt[presum[i]] += 1
        return ans
        
# @lc code=end



#
# @lcpr case=start
# [1,0,1,0,1]\n2\n
# @lcpr case=end

# @lcpr case=start
# [0,0,0,0,0]\n0\n
# @lcpr case=end

#

