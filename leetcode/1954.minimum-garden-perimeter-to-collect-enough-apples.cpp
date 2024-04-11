/*
 * @lc app=leetcode.cn id=1954 lang=cpp
 * @lcpr version=30121
 *
 * [1954] 收集足够苹果的最小花园周长
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
    using ll = long long;
    long long minimumPerimeter(long long neededApples) {
        if (neededApples <= 12) return 8;
        ll l = 1, r = 1e6;
        while (l < r) {
            ll mid = (l + r) >> 1;
            ll sum = mid * (mid + 1) * (mid + 2) / 2;
            if (sum >= neededApples) r = mid;
            else l = mid + 1;
        }
        if (l % 2 == 0) return 4 * l;
        return 4 * l + 4;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

// @lcpr case=start
// 1000000000\n
// @lcpr case=end

 */

