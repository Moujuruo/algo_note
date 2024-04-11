/*
 * @lc app=leetcode.cn id=1914 lang=cpp
 * @lcpr version=30121
 *
 * [1914] 循环轮转矩阵
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
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int layer = min(n, m) / 2;
        vector<tuple<int, int, int>> q;
        for (int i = 0; i < layer; i++) {
            for (int j = layer; j < n - layer - 1; j++) {
                q.emplace_back(j, i, grid[i][j]);
            }
            for (int j = i; j < m - i - 1; j++) {
                q.emplace_back(n - i - 1, j, grid[j][m - i - 1]);
            }
            for (int j = n - i - 1; j > i; j--) {
                q.emplace_back(j, m - i - 1, grid[n - i - 1][j]);
            }
            for (int j = m - i - 1; j > i; j--) {
                q.emplace_back(i, j, grid[j][i]);
            }
            int cnt = q.size();
            k = k % cnt;
            for (int j = 0; j < cnt; j++) {
                int idx = (j + cnt - k) % cnt;
                grid[get<0>(q[j])][get<1>(q[j])] = get<2>(q[idx]);
            }
        }
        return grid;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [[40,10],[30,20]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]\n2\n
// @lcpr case=end

 */

