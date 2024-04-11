#
# @lc app=leetcode.cn id=2024 lang=python3
# @lcpr version=30119
#
# [2024] 考试的最大困扰度
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        l, r = 0, 0
        n = len(answerKey)
        t = 0
        ans = 0
        for i in range(n):
            if answerKey[i] == 'F':
                t += 1
            while t > k:
                if answerKey[l] == 'F':
                    t -= 1
                l += 1
            r += 1               
            ans = max(ans, r - l)
        l, r = 0, 0
        t = 0
        for i in range(n):
            if answerKey[i] == 'T':
                t += 1
            while t > k:
                if answerKey[l] == 'T':
                    t -= 1
                l += 1
            r += 1               
            ans = max(ans, r - l)
        return ans     

# @lc code=end



#
# @lcpr case=start
# "TTFF"\n2\n
# @lcpr case=end

# @lcpr case=start
# "TFFT"\n1\n
# @lcpr case=end

# @lcpr case=start
# "TTFTTFTT"\n1\n
# @lcpr case=end

#

