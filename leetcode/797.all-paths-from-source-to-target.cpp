/*
 * @lc app=leetcode.cn id=797 lang=cpp
 * @lcpr version=30118
 *
 * [797] 所有可能的路径
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
    static const int N = 201;
    int h[N], ne[N], e[N], idx;
    int n;
    vector<vector<int>> ans;
    vector<int> path;
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a];
        h[a] = idx++;
    }
    void dfs(int u) {
        if (u == n - 1) {
            ans.push_back(path);
            return;
        }
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            path.push_back(v);
            dfs(v);
            path.pop_back();
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        for (int i = 0; i < n; i++) h[i] = -1;
        for (int i = 0; i < n; i++) {
            for (int &x: graph[i]) {
                add(i, x);
            }
        }
        path.push_back(0);
        dfs(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,1],[3,2,4],[3],[4],[]]\n
// @lcpr case=end

 */

