/*
 * @lc app=leetcode.cn id=1263 lang=cpp
 * @lcpr version=30118
 *
 * [1263] 推箱子
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
    
    int n, m;
    int dx[4] = {0, 0, 1, -1},
        dy[4] = {1, -1, 0, 0};



    int co_hash(int i, int j) {
        return i * m + j;
    }

    int minPushBox(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dist(n * m, vector<int>(n * m, -1));
        deque<pair<int, int>> q;
        int sx, sy, bx, by, tax, tay;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S') sx = i, sy = j;
                if (grid[i][j] == 'B') bx = i, by = j;
                if (grid[i][j] == 'T') tax = i, tay = j;
            }
        q.push_back({co_hash(sx, sy), co_hash(bx, by)});
        dist[co_hash(sx, sy)][co_hash(bx, by)] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            int si = x / m, sj = x % m,
                bi = y / m, bj = y % m;
            q.pop_front();
            if (bi == tax && bj == tay) return dist[co_hash(si, sj)][co_hash(bi, bj)];
            for (int i = 0; i < 4; i++) {
                int tx = si + dx[i],
                    ty = sj + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if (grid[tx][ty] == '#') continue;
                if (tx == bi && ty == bj) {
                    int bx = bi + dx[i],
                        by = bj + dy[i];
                    if (bx < 0 || bx >= n || by < 0 || by >= m) continue;
                    if (grid[bx][by] == '#') continue;
                    if (dist[co_hash(tx, ty)][co_hash(bx, by)] != -1) continue;
                    dist[co_hash(tx, ty)][co_hash(bx, by)] = dist[co_hash(si, sj)][co_hash(bi, bj)] + 1;
                    q.push_back({co_hash(tx, ty), co_hash(bx, by)});
                }                
                else {
                    if (dist[co_hash(tx, ty)][co_hash(bi, bj)] != -1) continue;
                    dist[co_hash(tx, ty)][co_hash(bi, bj)] = dist[co_hash(si, sj)][co_hash(bi, bj)];
                    q.push_front({co_hash(tx, ty), co_hash(bi, bj)});
                }
            }
            
        }
        return -1;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [["#","#","#","#","#","#"],["#","T","#","#","#","#"],["#",".",".","B",".","#"],["#",".","#","#",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]\n
// @lcpr case=end

// @lcpr case=start
// [["#","#","#","#","#","#"],["#","T","#","#","#","#"],["#",".",".","B",".","#"],["#","#","#","#",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]\n
// @lcpr case=end

// @lcpr case=start
// [["#","#","#","#","#","#"],["#","T",".",".","#","#"],["#",".","#","B",".","#"],["#",".",".",".",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]\n
// @lcpr case=end

 */

