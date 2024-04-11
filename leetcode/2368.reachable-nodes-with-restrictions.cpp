/*
 * @lc app=leetcode.cn id=2368 lang=cpp
 * @lcpr version=30117
 *
 * [2368] 受限条件下可到达节点的数目
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
    static const int N = 2e5 + 10;
    int h[N], e[N], ne[N], idx;
    int ans = 1;
    bool st[N];
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a];
        h[a] = idx++;
    }


    void bfs(int u) {
        queue<int> q;
        q.push(u);
        st[u] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (auto i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (st[j]) continue;
                st[j] = true;
                ans++;
                q.push(j);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        memset(h, -1, sizeof h);
        if (restricted.empty()) return n;
        for (auto edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        for (auto i: restricted) {
            st[i] = true;
        }
        bfs(0);
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]]\n[4,5]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]]\n[4,2,1]\n
// @lcpr case=end

 */

