/*
 * @lc app=leetcode.cn id=2581 lang=cpp
 * @lcpr version=30117
 *
 * [2581] 统计可能的树根数目
 */


// @lcpr-template-start
#include <cstddef>
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
    static const int N = 2e5 + 10;
    int ans = 0;
    using PII = pair<int, int>;
    struct pair_hash {
        size_t operator()(const PII& p) const {
            return ((size_t)p.first << 32) | p.second;
        }
    };
    unordered_set<PII, pair_hash> cnt;
    int h[N], e[N], ne[N], idx;
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a];
        h[a] = idx++;
    }
    void dfs(int u, int fa, int &sum) {
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            PII p = {u, j};
            if (cnt.count(p)) {
                sum++;
            }
            dfs(j, u, sum);
        }
    }

    void reroot(int u, int fa, int k, int sum) {
        if (sum >= k) ans++;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            PII p = {u, j}, q = {j, u};
            reroot(j, u, k, sum - cnt.count(p) + cnt.count(q));
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        memset(h, -1, sizeof h);
        for (auto edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        for (auto guess: guesses) {
            cnt.insert({guess[0], guess[1]});
        }
        int res = 0;
        dfs(0, -1, res);
        reroot(0, -1, k, res);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[1,2],[1,3],[4,2]]\n[[1,3],[0,1],[1,0],[2,4]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2],[2,3],[3,4]]\n[[1,0],[3,4],[2,1],[3,2]]\n1\n
// @lcpr case=end

 */

