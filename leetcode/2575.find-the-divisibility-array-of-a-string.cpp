/*
 * @lc app=leetcode.cn id=2575 lang=cpp
 * @lcpr version=30118
 *
 * [2575] 找出字符串的可整除数组
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
    vector<int> divisibilityArray(string word, int m) {
        int len = word.size();
        vector<int> ans;
        vector<int> a;
        for (int i = len - 1; i >= 0; i--) {
            a.push_back(word[i] - '0');
        }
        long long r = 0;
        for (int i = len - 1; i >= 0; i--) {
            r = r * 10 + a[i];
            if (r % m == 0)
                ans.push_back(1);
            else
                ans.push_back(0);
            r %= m;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "998244353"\n3\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n10\n
// @lcpr case=end

 */

