/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30118
 *
 * [79] 单词搜索
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
    int dx[4] = {0, 0, 1, -1},
        dy[4] = {1, -1, 0, 0};
    int n, m;
    bool Vis[201][201];
    bool dfs(vector<vector<char>>& board, string &word, int x, int y, int idx) {
        if (board[x][y] != word[idx]) return false; 
        if (idx == word.size() - 1 && board[x][y] == word[word.size() - 1]) return true;
        char t = board[x][y];
        board[x][y] = ' ';
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i],
                ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if (dfs(board, word, tx, ty, idx + 1)) 
                return true;
        }
        board[x][y] = t;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) 
                        return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */

