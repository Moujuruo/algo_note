/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=30119
 *
 * [37] 解数独
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
    unordered_set<int> row[9], col[9], block[9];
    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (x == 9) {
            return true;
        }
        if (y == 9) {
            return dfs(board, x + 1, 0);
        }
        if (board[x][y] != '.') {
            return dfs(board, x, y + 1);
        }
        for (int i = 1; i <= 9; i++) {
            if (row[x].count(i) || col[y].count(i) || block[x / 3 * 3 + y / 3].count(i)) continue;
            row[x].insert(i);
            col[y].insert(i);
            block[x / 3 * 3 + y / 3].insert(i);
            board[x][y] = i + '0';
            if(dfs(board, x, y + 1))    
                return true;
            if (board[x][y] == i + '0') {
                row[x].erase(i);
                col[y].erase(i);
                block[x / 3 * 3 + y / 3].erase(i);
                board[x][y] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i].insert(num);
                    col[j].insert(num);
                    block[i / 3 * 3 + j / 3].insert(num);
                }
            }
        }
        dfs(board, 0, 0);

    }
};
// @lc code=end



/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */

