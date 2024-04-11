#
# @lc app=leetcode.cn id=2671 lang=python3
# @lcpr version=30119
#
# [2671] 频率跟踪器
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class FrequencyTracker:

    def __init__(self):
        self.freq = {}
        self.num = {}

    def add(self, number: int) -> None:
        if number in self.num:
            self.freq[self.num[number]] -= 1
            self.num[number] += 1
            # self.freq[self.num[number]] += 1
            if self.num[number] in self.freq:
                self.freq[self.num[number]] += 1
            else:
                self.freq[self.num[number]] = 1
        else:
            self.num[number] = 1
            if 1 in self.freq: 
                self.freq[1] += 1
            else:
                self.freq[1] = 1


    def deleteOne(self, number: int) -> None:
        if number in self.num:
            self.freq[self.num[number]] -= 1
            self.num[number] -= 1
            if self.num[number] == 0:
                del self.num[number]
            else:
                self.freq[self.num[number]] += 1

    def hasFrequency(self, frequency: int) -> bool:
        return frequency in self.freq and self.freq[frequency] > 0



# Your FrequencyTracker object will be instantiated and called as such:
# obj = FrequencyTracker()
# obj.add(number)
# obj.deleteOne(number)
# param_3 = obj.hasFrequency(frequency)
# @lc code=end



