/*
 * @lc app=leetcode.cn id=2673 lang=cpp
 * @lcpr version=30116
 *
 * [2673] 使二叉树所有路径值相等的最小代价
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        for (int i = n / 2; i >= 1; i--) {
            res += abs(cost[2 * i - 1] - cost[2 * i]);
            cost[i - 1] += max(cost[2 * i], cost[2 * i - 1]);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[1,5,2,2,3,3,1]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[5,3,3]\n
// @lcpr case=end

 */

