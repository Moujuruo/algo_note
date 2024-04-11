/*
 * @lc app=leetcode.cn id=784 lang=cpp
 * @lcpr version=30119
 *
 * [784] 字母大小写全排列
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
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        dfs(s, 0, ans);
        return ans;
    }

    void dfs(string &s, int idx, vector<string> &ans) {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }
        dfs(s, idx + 1, ans);
        if (isalpha(s[idx])) {
            s[idx] ^= 32;
            dfs(s, idx + 1, ans);
            s[idx] ^= 32;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a1b2"\n
// @lcpr case=end

// @lcpr case=start
// "3z4"\n
// @lcpr case=end

 */

