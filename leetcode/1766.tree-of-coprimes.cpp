/*
 * @lc app=leetcode.cn id=1766 lang=cpp
 * @lcpr version=30122
 *
 * [1766] 互质树
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
const int MX = 51;
vector<int> g[MX];

auto gcd(int a, int b) -> int {
    return b ? gcd(b, a % b) : a;
}

auto init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = 1; j < MX; j++) {
            if (gcd(i, j) == 1) {
                g[i].push_back(j);
            }
        }
    }
    return 0;
}();

class Solution {
public:
    using PII = pair<int, int>;
    static const int N = 2e5 + 10;
    int h[N], e[N], ne[N], idx;
    vector<int> ans;
    PII q[N];

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    void dfs(int fa, int depth, int idx, vector<int> &nums) {
        int val = nums[idx];
        int max_depth = 0;
        for (auto j: g[val]) {
            auto [dep, id] = q[j];
            if (dep > max_depth) {
                max_depth = dep;
                ans[idx] = id;
            }
        }
        auto saved = q[val];
        q[val] = {depth, idx};
        for (int i = h[idx]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            dfs(idx, depth + 1, j, nums);
        }
        q[val] = saved;
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        ans = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            q[i] = {-1, -1};
        }

        memset(h, -1, sizeof h);
        for (auto &e : edges) {
            add(e[0], e[1]);
            add(e[1], e[0]);
        }
        dfs(-1, 1, 0, nums);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,3,2]\n[[0,1],[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [5,6,10,2,3,6,15]\n[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]\n
// @lcpr case=end

 */

