/*
 * @lc app=leetcode.cn id=309 lang=cpp
 * @lcpr version=30117
 *
 * [309] 买卖股票的最佳时机含冷冻期
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
    static const int N = 5010, INF = 0x3f3f3f3f;
    int f[N][3];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(f, -0x3f, sizeof f);
        f[0][0] = -prices[0];
        f[0][1] = 0; f[0][2] = 0;
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = max(f[i - 1][0] + prices[i], f[i][1]);
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

