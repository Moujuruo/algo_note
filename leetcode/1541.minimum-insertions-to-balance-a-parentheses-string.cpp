/*
 * @lc app=leetcode.cn id=1541 lang=cpp
 * @lcpr version=30121
 *
 * [1541] 平衡括号字符串的最少插入次数
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
    int minInsertions(string s) {
        int k = 0;
        int size = s.size();
        int ans = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') 
                k ++;
            if (s[i] == ')') {
                if (!k) {
                    ans ++;
                }
                else {
                    k --;
                }
                if (i + 1 == size || s[i + 1] != ')')
                    ans ++;
                else
                    i += 1;
            }
        }
        ans += k * 2;
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()))"\n
// @lcpr case=end

// @lcpr case=start
// "())"\n
// @lcpr case=end

// @lcpr case=start
// "))())("\n
// @lcpr case=end

// @lcpr case=start
// "(((((("\n
// @lcpr case=end

// @lcpr case=start
// ")))))))"\n
// @lcpr case=end

 */

