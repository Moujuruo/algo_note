#
# @lc app=leetcode.cn id=307 lang=python3
# @lcpr version=30119
#
# [307] 区域和检索 - 数组可修改
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class NumArray:

    def lowbit(self, x):
        return x & -x
    
    def add(self, x, u):
        while x <= self.n:
            self.tr[x] += u
            x += self.lowbit(x)

    def sum(self, x) -> int:
        res = 0
        while x:
            res += self.tr[x]
            x -= self.lowbit(x)
        return res

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.tr = [0] * (self.n + 1)
        self.nums = [0] + nums
        for i in range(1, self.n + 1):
            self.tr[i] += nums[i]
            j = i + self.lowbit(i)
            if j <= self.n:
                self.tr[j] += self.tr[i]

    def update(self, index: int, val: int) -> None:
        value = val - self.nums[index + 1]
        self.nums[index + 1] = val
        self.add(index + 1, value)


    def sumRange(self, left: int, right: int) -> int:
        return self.sum(right + 1) - self.sum(left)



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
# @lc code=end



#
# @lcpr case=start
# ["NumArray", "sumRange", "update", "sumRange"][[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]\n
# @lcpr case=end

#

