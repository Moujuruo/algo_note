/*
 * @lc app=leetcode.cn id=1883 lang=cpp
 * @lcpr version=30122
 *
 * [1883] 准时抵达会议现场的最小跳过休息次数
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
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        if (accumulate(dist.begin(), dist.end(), 0) > speed * hoursBefore) {
            return -1;
        }
        int n = dist.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; ; i++) {
            for (int j = 0; j < n - 1; j++) {
                dp[i][j + 1] = (dp[i][j] + dist[j] + speed - 1) / speed * speed;
                if (i) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + dist[j]);
                }
            }
            if (dp[i][n - 1] + dist[n - 1] <= (long long)speed * hoursBefore) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [7,3,5,5]\n2\n10\n
// @lcpr case=end

// @lcpr case=start
// [7,3,5,5]\n1\n10\n
// @lcpr case=end

 */

