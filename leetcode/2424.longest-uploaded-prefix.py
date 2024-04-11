#
# @lc app=leetcode.cn id=2424 lang=python3
# @lcpr version=30119
#
# [2424] 最长上传前缀
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class LUPrefix:

    def __init__(self, n: int):
        self.video = [1] * n
        self.l = 0

    def upload(self, video: int) -> None:
        self.video[video - 1] = 0
        while self.l < len(self.video) and self.video[self.l] == 0:
            self.l += 1


    def longest(self) -> int:
        return self.l



# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()
# @lc code=end



#
# @lcpr case=start
# ["LUPrefix", "upload", "longest", "upload", "longest", "upload", "longest"][[4], [3], [], [1], [], [2], []]\n
# @lcpr case=end

#

