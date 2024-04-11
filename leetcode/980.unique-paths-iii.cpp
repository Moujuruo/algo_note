/*
 * @lc app=leetcode.cn id=980 lang=cpp
 * @lcpr version=30119
 *
 * [980] 不同路径 III
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
    int ans = 0;
    int n, m;
    int cnt;
    int sx, sy, ex, ey;
    int dx[4] = {0, 0, 1, -1},
        dy[4] = {1, -1, 0, 0};
    bool Vis[21][21];

    void dfs(vector<vector<int>>& grid, int x, int y, int step) {
        if (x == ex && y == ey) {
            if (step == cnt + 1) ans++;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i],
                ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if (grid[tx][ty] == -1 || Vis[tx][ty]) continue;
            Vis[tx][ty] = true;
            dfs(grid, tx, ty, step + 1);
            Vis[tx][ty] = false;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) cnt++;
                else if (grid[i][j] == 1) sx = i, sy = j;
                else if (grid[i][j] == 2) ex = i, ey = j;
            }
        }
        Vis[sx][sy] = true;
        dfs(grid, sx, sy, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0],[0,0,0,0],[0,0,0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[2,0]]\n
// @lcpr case=end

 */

