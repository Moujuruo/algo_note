/*
 * @lc app=leetcode.cn id=785 lang=cpp
 * @lcpr version=30116
 *
 * [785] 判断二分图
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
    static const int N = 1e5 + 10;
    int e[N], ne[N], h[N], idx;
    int color[N];
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a];
        h[a] = idx ++;
    }
    bool dfs(int u, int c) {
        color[u] = c;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (!color[j]) {
                if (!dfs(j, 3 - c)) return false;
            }
            else if (color[j] == c) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        memset(h, -1, sizeof h);
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            for (auto j: graph[i]) {
                add(i, j);
                add(j, i);
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!color[i]) {
                if (!dfs(i, 1)) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[0,2],[0,1,3],[0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[0,2],[1,3],[0,2]]\n
// @lcpr case=end

 */

