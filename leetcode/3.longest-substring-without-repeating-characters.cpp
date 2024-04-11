/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30113
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n < 2) return n;
        int ans = 0;
        unordered_map<char, int> HashSet;
        for (int i = 0, j = 0; i < n; i++) {
            HashSet[s[i] - '0'] ++;
            while (HashSet[s[i] - '0'] > 1) {
                HashSet[s[j] - '0'] --;
                j ++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

