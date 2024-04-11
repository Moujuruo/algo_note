#
# @lc app=leetcode.cn id=846 lang=python3
# @lcpr version=30119
#
# [846] 一手顺子
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        hand.sort()
        hand_dict = {}
        for i in hand:
            if i in hand_dict:
                hand_dict[i] += 1
            else:
                hand_dict[i] = 1
        for i in hand:
            if hand_dict[i] > 0:
                for j in range(groupSize):
                    if i+j not in hand_dict or hand_dict[i+j] == 0:
                        return False
                    hand_dict[i+j] -= 1
        return True
# @lc code=end



#
# @lcpr case=start
# [1,2,3,6,2,3,4,7,8]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,5]\n4\n
# @lcpr case=end

#

