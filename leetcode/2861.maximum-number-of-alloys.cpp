/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 * @lcpr version=30113
 *
 * [2861] 最大合金数
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
    typedef long long ll;
public:

    ll check(vector<int>& machine, vector<int>& stock, vector<int>& cost, ll x) {
        ll res = 0;
        for (int i = 0; i < cost.size(); i++) {
            ll add = max(machine[i] * x - stock[i], 0LL);
            res += add * cost[i];
        }
        return res;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        int mx = budget + *min_element(stock.begin(), stock.end());
        for (auto machine: composition) {
            int l = 0, r = mx;
            while (l < r) {
                ll mid = (l + r + 1) / 2;
                if (check(machine, stock, cost, mid) <= budget) l = mid;
                else r = mid - 1;
            }
            ans = max(ans, l);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,0]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,100]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n10\n[[2,1],[1,2],[1,1]]\n[1,1]\n[5,5]\n
// @lcpr case=end

 */

