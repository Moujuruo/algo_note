/*
 * @lc app=leetcode.cn id=2917 lang=cpp
 * @lcpr version=30117
 *
 * [2917] 找出数组中的 K-or 值
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
    int lowbit(int x) {
        return x & -x;
    }
    
    int f[32];
    int findKOr(vector<int>& nums, int k) {
        memset(f, 0, sizeof f);
        // 构造一个字典，记录lowbit与第i位的关系
        // 例如 lowbit = 1, 为第0位
        // lowbit = 2, 为第1位
        // lowbit = 4, 为第2位
        unordered_map<int, int> mp;
        for (int i = 0; i < 32; i++) {
            mp[1 << i] = i;
        }
        for (auto &num: nums) {
            while (num) {
                int bit = lowbit(num);
                f[mp[bit]]++;
                num -= bit;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (f[i] >= k) {
                res += 1 << i;
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,12,9,8,9,15]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,12,1,11,4,5]\n6\n
// @lcpr case=end

// @lcpr case=start
// [10,8,5,9,11,6,8]\n1\n
// @lcpr case=end

 */

