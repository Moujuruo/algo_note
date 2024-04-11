/*
 * @lc app=leetcode.cn id=2808 lang=cpp
 * @lcpr version=30113
 *
 * [2808] 使循环数组所有元素相等的最少秒数
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
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> Map;
        for (int i = 0; i < nums.size(); i++) {
            Map[nums[i]].push_back(i);
        }
        int ans = nums.size();
        for (auto item: Map) {
            auto co = item.second;
            int len = co.size();

            int res = nums.size() - (co[len - 1] - co[0]);
            for (int i = 1; i < len; i++) {
                res = max(res, co[i] - co[i - 1]);
            }
            ans = min(ans, res);
        }
        return ans / 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

 */

