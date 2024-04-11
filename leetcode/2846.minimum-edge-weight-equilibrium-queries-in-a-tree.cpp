/*
 * @lc app=leetcode.cn id=2846 lang=cpp
 * @lcpr version=30113
 *
 * [2846] 边权重均等查询
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
    static const int N = 1e5 + 10;
    int h[N], ne[N], e[N], w[N], idx, d[N];
    bool st[N];
    int cnt[N][27], anc[N][27];
public:
    void add(int a, int b, int u) {
        e[idx] = b, w[idx] = u;
        ne[idx] = h[a];
        h[a] = idx++;
    }
    void dfs(int x, int fa, int depth) {
        st[x] = true;
        d[x] = depth;
        anc[x][0] = fa;
        for (int i = h[x]; i != -1; i = ne[i]) {
            int j = e[i], value = w[i];
            if (st[j]) continue;
            cnt[j][value] = 1;
            for (int k = 1; k <= 26; k++) {
                cnt[j][k] += cnt[x][k];
            }
            dfs(j, x, depth + 1);
        }
    }
    void swim(int &x, int h) {
        for (int i = 0; h > 0; i++) {
            if (h & 1) x = anc[x][i];
            h >>= 1;
        }
    }

    int find(int a, int b) {
        if (d[a] < d[b]) swap(a, b);
        swim(a, d[a] - d[b]);
        if (a == b) return a;
        for (int i = 19; i >= 0; i--) {
            if (anc[a][i] != anc[b][i]) {
                a = anc[a][i];
                b = anc[b][i];
            }
        }
        return anc[a][0];
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int> ans;
        memset(h, -1, sizeof h);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            int c = edges[i][2];
            add(a, b, c);
            add(b, a, c);
        }
        dfs(0, 0, 1);
        for (int j = 1; j < 20; j++) 
            for (int i = 0; i < n; i++)
                anc[i][j] = anc[anc[i][j - 1]][j - 1];
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0], b = queries[i][1];
            int lca = find(a, b);
            int s = 0, Max = 0;
            for (int j = 1; j <= 26; j++) {
                int t = cnt[a][j] + cnt[b][j] - 2 * cnt[lca][j];
                s += t;
                Max = max(Max, t);
            }
            ans.push_back(s - Max);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]]\n[[0,3],[3,6],[2,6],[0,6]]\n
// @lcpr case=end

// @lcpr case=start
// 8\n[[1,2,6],[1,3,4],[2,4,6],[2,5,3],[3,6,6],[3,0,8],[7,0,2]]\n[[4,6],[0,4],[6,5],[7,4]]\n
// @lcpr case=end

 */

