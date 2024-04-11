#
# @lc app=leetcode.cn id=2580 lang=python3
# @lcpr version=30119
#
# [2580] 统计将重叠区间合并成组的方案数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def merge_interval(self, ranges: List[List[int]]) -> List[List[int]]:
        # 按照区间的左端点排序
        ranges.sort(key=lambda x: x[0])
        st, ed = -1, -1
        n = len(ranges)
        res = []
        for i in range(n):
            if ranges[i][0] > ed:
                if st != -1:
                    res.append([st, ed])
                st, ed = ranges[i]
            else:
                ed = max(ed, ranges[i][1])
        if st != -1:
            res.append([st, ed])
        return res


    def countWays(self, ranges: List[List[int]]) -> int:
        mod = 10 ** 9 + 7
        # mod = 1e9 + 7
        ranges = self.merge_interval(ranges)
        n = len(ranges)
        return pow(2, n, mod)
# @lc code=end



#
# @lcpr case=start
# [[6,10],[5,15]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,3],[10,20],[2,5],[4,8]]\n
# @lcpr case=end

#

