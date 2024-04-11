/*
 * @lc app=leetcode.cn id=212 lang=cpp
 * @lcpr version=30118
 *
 * [212] 单词搜索 II
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
    unordered_set<string> build_words;
    int dx[4] = {0, 0, 1, -1},
        dy[4] = {1, -1, 0, 0};
    int n, m;
    static const int N = 1e5 + 10;
    int son[N][26], cnt[N], idx;

    void insert(string &s) {
        int p = 0;
        for (auto c: s) {
            int u = c - 'a';
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }

    bool isPrefix(string &s, int &isWord) {
        int p = 0;
        for (auto c: s) {
            int u = c - 'a';
            if (!son[p][u]) return false;
            p = son[p][u];
        }
        isWord = cnt[p];
        return true;
    }



    void dfs(vector<vector<char>>& board, string word, int x, int y) {
        word += board[x][y];
        int isWord = 0;
        if (!isPrefix(word, isWord)) return;
        if (isWord) build_words.insert(word);
        if (word.size() > 10) return;
        char t = board[x][y];
        board[x][y] = ' ';
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i],
                ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if (board[tx][ty] != ' ')
                dfs(board, word, tx, ty);
        }
        board[x][y] = t;
    }



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();

        for (auto word: words) {
            insert(word);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(board, "", i, j);
            }
        }

        vector<string> ans(build_words.begin(), build_words.end());
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"],["c","d"]]\n["abcb"]\n
// @lcpr case=end

 */

