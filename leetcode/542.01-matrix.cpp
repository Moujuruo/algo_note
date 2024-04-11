/*
 * @lc app=leetcode.cn id=542 lang=cpp
 * @lcpr version=30118
 *
 * [542] 01 矩阵
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
    static const int N = 1e4 + 10;
    int n, m;
    vector<vector<int>> ans;
    int dx[4] = {0, 0, 1, -1},
        dy[4] = {1, -1, 0, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        ans = vector<vector<int>>(n, vector<int>(m, -1));
        queue<PII> q;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i],
                    ty = y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if (ans[tx][ty] == -1) {
                    ans[tx][ty] = ans[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,1,0],[1,1,1]]\n
// @lcpr case=end

 */

