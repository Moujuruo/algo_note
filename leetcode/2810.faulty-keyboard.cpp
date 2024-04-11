/*
 * @lc app=leetcode.cn id=2810 lang=cpp
 * @lcpr version=30121
 *
 * [2810] 故障键盘
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
    string finalString(string s) {
        int size = s.size();
        string res;
        for (int i = 0; i < size; i++) {
            if (s[i] != 'i')
                res += s[i];
            else {
                int cnt = 0;
                while (i < size && s[i] == 'i') {
                    cnt ++;
                    i ++;
                }
                i --;
                if (cnt % 2 == 1)
                    reverse(res.begin(), res.end());

                // reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "string"\n
// @lcpr case=end

// @lcpr case=start
// "poiinter"\n
// @lcpr case=end

 */

