/*
 * @lc app=leetcode.cn id=2617 lang=cpp
 * @lcpr version=30119
 *
 * [2617] 网格图中最少访问的格子数
 */


// @lcpr-template-start
#include <set>
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
    int n, m;
    // dist
    vector<vector<int>> dist;

    int minimumVisitedCells(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dist = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        set<int> R[n], C[m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) 
                    continue;
                R[i].insert(j);
                C[j].insert(i);
            }
        }
        
        queue<PII> q;
        q.push({0, 0});
        dist[0][0] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int g = grid[x][y];

            auto it = R[x].upper_bound(y);
            while (it != R[x].end()) {
                if (*it > g + y) break;
                q.push({x, *it});
                dist[x][*it] = dist[x][y] + 1;
                C[*it].erase(x);
                it = R[x].erase(it);
            }

            it = C[y].upper_bound(x);
            while (it != C[y].end()) {
                if (*it > g + x) break;
                q.push({*it, y});
                dist[*it][y] = dist[x][y] + 1;
                R[*it].erase(y);
                it = C[y].erase(it);
            }

        }
        return dist[n - 1][m - 1] == INT_MAX ? -1 : dist[n - 1][m - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,0],[1,0,0]]\n
// @lcpr case=end

 */

