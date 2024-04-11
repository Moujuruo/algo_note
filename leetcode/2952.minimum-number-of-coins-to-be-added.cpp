/*
 * @lc app=leetcode.cn id=2952 lang=cpp
 * @lcpr version=30121
 *
 * [2952] 需要添加的硬币的最小数量
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
    int minimumAddedCoins(vector<int>& coins, int target) {
        int max_get = 0;
        sort(coins.begin(), coins.end());
        int n = coins.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            while (coins[i] > max_get + 1 && max_get < target) {
                ans ++;
                max_get = max_get * 2 + 1;
            }
            max_get = max_get + coins[i];
            if (max_get >= target) return ans;
        }
        while (max_get < target) {
            ans ++;
            max_get = 2 * max_get + 1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,10]\n19\n
// @lcpr case=end

// @lcpr case=start
// [1,4,10,5,7,19]\n19\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n20\n
// @lcpr case=end

 */

