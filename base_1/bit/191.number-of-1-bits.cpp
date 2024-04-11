/*
 * @lc app=leetcode.cn id=191 lang=cpp
 * @lcpr version=30113
 *
 * [191] 位1的个数
 */


// @lcpr-template-start
#include <cstdint>
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
    int lowbit(uint32_t x) {
        return x & (-x);
    }
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans++;
            n -= lowbit(n);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 00000000000000000000000000001011\n
// @lcpr case=end

// @lcpr case=start
// 00000000000000000000000010000000\n
// @lcpr case=end

// @lcpr case=start
// 11111111111111111111111111111101\n
// @lcpr case=end

 */

