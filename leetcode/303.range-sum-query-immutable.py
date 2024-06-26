#
# @lc app=leetcode.cn id=303 lang=python3
# @lcpr version=30119
#
# [303] 区域和检索 - 数组不可变
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.sums = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            self.sums[i + 1] = self.sums[i] + nums[i]


    def sumRange(self, left: int, right: int) -> int:
        return self.sums[right + 1] - self.sums[left]



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
# @lc code=end



#
# @lcpr case=start
# ["NumArray", "sumRange", "sumRange", "sumRange"][[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]\n
# @lcpr case=end

#

