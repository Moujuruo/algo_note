/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 * @lcpr version=30118
 *
 * [1162] 地图分析
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
    using PII = pair<int, int>;
    static const int N = 110;
    int dist[N][N];
    int dx[4] = {0, 0, 1, -1},
        dy[4] = {1, -1, 0, 0};
    int maxDistance(vector<vector<int>>& grid) {
        memset(dist, -1, sizeof dist);
        queue<PII> q;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        if (q.size() == n * m || q.empty()) return -1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i],
                    ty = y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m)     
                    continue;
                if (dist[tx][ty] != -1) continue;
                dist[tx][ty] = dist[x][y] + 1;
                q.push({tx, ty});
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                ans = max(ans, dist[i][j]);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,1],[0,0,0],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,0,0],[0,0,0]]\n
// @lcpr case=end

 */

