/*
 * @lc app=leetcode.cn id=2290 lang=cpp
 * @lcpr version=30118
 *
 * [2290] 到达角落需要移除障碍物的最小数目
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
    deque<PII> q;
    vector<vector<int>> dist;
    int dx[4] = {0, 0, 1, -1},
        dy[4] = {1, -1, 0, 0};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dist = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        q.push_front({0, 0});
        dist[0][0] = grid[0][0];
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i],
                    ty = y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                int newDist = dist[x][y] + grid[tx][ty];
                if (newDist < dist[tx][ty]) {
                    dist[tx][ty] = newDist;
                    if (grid[tx][ty] == 1) {
                        q.push_back({tx, ty});
                    } else {
                        q.push_front({tx, ty});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1],[1,1,0],[1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]\n
// @lcpr case=end

 */

