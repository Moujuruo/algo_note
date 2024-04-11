/*
 * @lc app=leetcode.cn id=188 lang=cpp
 * @lcpr version=30117
 *
 * [188] 买卖股票的最佳时机 IV
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
    int f[1001][101][2];
    int maxProfit(int k, vector<int>& prices) { 
        memset(f, -0x3f, sizeof f);
        int len = prices.size();
        for (int i = 0; i <= len; i++) {
            f[i][0][0] = 0;
        }
        for (int i = 1; i <= k; i++) {
            f[0][i][0] = 0;
        }
        f[0][1][1] = -prices[0];
        for (int i = 1; i < len; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + prices[i]);
                f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i]);
            }
        }
        int res = 0;
        for (int i = 1; i <= k; i++) {
            res = max(res, f[len - 1][i][0]);
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[2,4,1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[3,2,6,5,0,3]\n
// @lcpr case=end

 */

