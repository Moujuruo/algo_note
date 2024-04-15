/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 * @lcpr version=30122
 *
 * [1438] 绝对差不超过限制的最长连续子数组
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
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> mp;
        int left = 0, n = nums.size();
        int ans = 0;
        for (int right = 0; right < n; right++) {
            mp[nums[right]]++;
            while (mp.rbegin()->first - mp.begin()->first > limit) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,2,4,7]\n4\n
// @lcpr case=end

// @lcpr case=start
// [10,1,2,4,7,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,2,4,4,2,2]\n0\n
// @lcpr case=end

 */

