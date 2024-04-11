/*
 * @lc app=leetcode.cn id=834 lang=cpp
 * @lcpr version=30117
 *
 * [834] 树中距离之和
 */


// @lcpr-template-start
#include <type_traits>
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
    static const int N = 6e4 + 10, M = 3e4 + 10;
    vector<int> Size, ans;
    int e[N], ne[N], h[N], idx;
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a];
        h[a] = idx++;
    }
    void dfs(int u, int fa, int depth) {
        ans[0] += depth;
        Size[u] = 1;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            dfs(j, u, depth + 1);
            Size[u] += Size[j];
        }
    }

    void reroot(int u, int fa, int n) {
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            ans[j] = ans[u] - Size[j] + n - Size[j];
            reroot(j, u, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        memset(h, -1, sizeof h);
        for (auto edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        Size.resize(n);
        ans.resize(n);
        dfs(0, -1, 0);
        reroot(0, -1, n);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[0,1],[0,2],[2,3],[2,4],[2,5]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

 */

