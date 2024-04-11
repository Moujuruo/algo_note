/*
 * @lc app=leetcode.cn id=2009 lang=cpp
 * @lcpr version=30121
 *
 * [2009] 使数组连续的最少操作数
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
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // 去重
        int m = unique(nums.begin(), nums.end()) - nums.begin();
        int ans = 0, l = 0;
        for (int r = 0; r < m; r++) {
            while (nums[l] < nums[r] - n + 1) {
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return n - ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,100,1000]\n
// @lcpr case=end

// @lcpr case=start
// [8,5,9,9,8,4]\n
// @lcpr case=end
 */

