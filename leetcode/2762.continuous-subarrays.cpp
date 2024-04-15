/*
 * @lc app=leetcode.cn id=2762 lang=cpp
 * @lcpr version=30122
 *
 * [2762] 不间断子数组
 */


// @lcpr-template-start
#include <map>
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
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> mp;
        long long ans = 0;
        int left = 0, n = nums.size();
        for (int right = 0; right < n; right++) {
            mp[nums[right]]++;
            while (mp.rbegin()->first - mp.begin()->first > 2) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

