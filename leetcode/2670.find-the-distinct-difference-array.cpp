/*
 * @lc app=leetcode.cn id=2670 lang=cpp
 * @lcpr version=30113
 *
 * [2670] 找出不同元素数目差数组
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
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_set<int> LMap, RMap;
        int len = nums.size();
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        left[0] = 1; LMap.insert(nums[0]);
        for (int i = 1; i < len; i++) {
            left[i] += left[i - 1];
            if (!LMap.count(nums[i])) {
                LMap.insert(nums[i]);
                left[i] += 1;
            }
        }
        right[len - 1] = 0;
        for (int i = len - 2; i >= 0; i--) {
            right[i] += right[i + 1];
            if (!RMap.count(nums[i + 1])) {
                RMap.insert(nums[i + 1]);
                right[i] += 1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < len; i++) {
            ans.push_back(left[i] - right[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,4,2]\n
// @lcpr case=end

 */

