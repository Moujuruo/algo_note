/*
 * @lc app=leetcode.cn id=126 lang=cpp
 * @lcpr version=30118
 *
 * [126] 单词接龙 II
 */


// @lcpr-template-start
#include <stdexcept>
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
    vector<vector<string>> ans;
    unordered_set<string> dict;
    unordered_map<string, vector<string>> tree;
    bool found = false;

    void extend(queue<string> &q, unordered_map<string, vector<string>> &fa, unordered_map<string, vector<string>> &fb, bool reverse) {
        unordered_set<string> visited;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            auto word = q.front();
            q.pop();
            for (int i = 0; i < word.size(); i++) {
                string newWord = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    newWord[i] = c;
                    if (!dict.count(newWord)) continue;
                    if (fb.count(newWord)) {
                        found = true;
                        reverse ? tree[word].push_back(newWord) : tree[newWord].push_back(word);
                    }
                    else if (!visited.count(newWord)) {
                        if (!fa.count(newWord)) {
                            q.push(newWord);
                            
                        }

                }
            }
        }
        for (auto &s: visited) dict.erase(s);
    }

    void bfs(string beginword, string endWord, vector<string> &wordList) {
        queue<string> qa, qb;
        unordered_map<string, vector<string>> fa, fb;
        qa.push(beginword);
        qb.push(endWord);
        fa[beginword] = {beginword};
        fb[endWord] = {endWord};
        while (!found && qa.size() && qb.size()) {
            if (qa.size() <= qb.size()) 
                extend(qa, fa, fb, false);
            else
                extend(qb, fb, fa, true);
        }

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (auto &w: wordList) dict.insert(w);
        if (!dict.count(endWord)) return ans;
        bfs(beginWord, endWord, wordList);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]\n
// @lcpr case=end

// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log"]\n
// @lcpr case=end

 */

