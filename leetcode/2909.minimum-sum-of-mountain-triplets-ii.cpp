/*
 * @lc app=leetcode.cn id=2909 lang=cpp
 * @lcpr version=30121
 *
 * [2909] 元素和最小的山形三元组 II
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
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_min(n), right_min(n);
        left_min[0] = INT_MAX;;
        for (int i = 1; i < n; i++) {
            left_min[i] = min(left_min[i - 1], nums[i - 1]);
        }
        right_min[n - 1] = INT_MAX;
        for (int i = n - 2; i >= 0; i--) {
            right_min[i] = min(right_min[i + 1], nums[i + 1]);
        }
        int ans = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > left_min[i] && nums[i] > right_min[i]) {
                ans = min(ans, nums[i] + left_min[i] + right_min[i]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
        
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,6,1,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,7,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,3,4,5]\n
// @lcpr case=end

 */

