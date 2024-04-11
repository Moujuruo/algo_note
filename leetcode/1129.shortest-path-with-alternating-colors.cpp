/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 * @lcpr version=30121
 *
 * [1129] 颜色交替的最短路径
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
    static const int N = 1610;
    int h[N], ne[N], e[N], w[N], idx;

    void add(int a, int b, int c) {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    using PII = pair<int, int>;

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        memset(h, -1, sizeof h);
        idx = 0;
        for (auto& e : redEdges) {
            add(e[0], e[1], 0);
        }
        for (auto& e : blueEdges) {
            add(e[0], e[1], 1);
        }
        vector<int> ans(n, -1);
        ans[0] = 0;
        queue<PII> q;
        q.push({0, -1});
        vector<vector<int>> dis(n, vector<int>(2, INT_MAX));
        dis[0][0] = dis[0][1] = 0;
        while (!q.empty()) {
            auto [u, color] = q.front(); q.pop();
            for (int i = h[u]; ~i; i = ne[i]) {
                int v = e[i], c = w[i];
                if (color == -1 || c != color) { 
                    if (dis[u][color == -1 ?  : color] + 1 < dis[v][c]) {
                        dis[v][c] = dis[u][color == -1 ?  : color] + 1;
                        q.push({v, c});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int ans1 = dis[i][0], ans2 = dis[i][1];
            if (ans1 == INT_MAX && ans2 == INT_MAX) {
                ans[i] = -1;
            } else {
                ans[i] = min(ans1, ans2);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,1],[1,2]]\n[]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1]]\n[[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1],[0,2]]\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1],[3,2],[1,0],[4,3],[2,4]]\n[[2,4],[2,2],[1,3]]\n
// @lcpr case=end

 */

