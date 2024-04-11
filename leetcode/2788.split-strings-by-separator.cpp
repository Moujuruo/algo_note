/*
 * @lc app=leetcode.cn id=2788 lang=cpp
 * @lcpr version=30113
 *
 * [2788] 按分隔符拆分字符串
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
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for (auto &word: words) {
            int n = word.size();
            int i = 0;
            if (word[0] == separator)
                i = 1;
            string tmp;
            for ( ; i < n; i++) {
                if (word[i] == separator) {
                    if (tmp.size())
                        res.push_back(tmp);
                    tmp.clear();
                } else {
                    tmp.push_back(word[i]);
                }
            }
            if (tmp.size())
                res.emplace_back(tmp);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["one.two.three","four.five","six"]\n"."\n
// @lcpr case=end

// @lcpr case=start
// ["$easy$","$problem$"]\n"$"\n
// @lcpr case=end

// @lcpr case=start
// ["|||"]\n"|"\n
// @lcpr case=end

 */

