// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2908 lang=cpp
 * @lcpr version=30121
 *
 * [2908] 元素和最小的山形三元组 I
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
        int left_min = -1, right_min = -1;
        int ans = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            left_min = INT_MAX, right_min = INT_MAX;
            for (int j = 0; j < i - 1; j++) {
                if (nums[j] < nums[i] && nums[j] < left_min) {
                    left_min = nums[j];
                }
            }
            if (left_min == INT_MAX) continue;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i] && nums[j] < right_min) {
                    right_min = nums[j];
                }
            }
            if (right_min == INT_MAX) continue;
            ans = min(ans, nums[i] + left_min + right_min);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minimumSum
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




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

