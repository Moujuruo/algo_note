/*
 * @lc app=leetcode.cn id=2321 lang=cpp
 * @lcpr version=30121
 *
 * [2321] 拼接数组的最大分数
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

    int sum(vector<int> &nums) {
        int sum = 0, res = 0;
        for (auto x: nums) {
            sum += x;
            if (sum < 0) sum = 0;
            res = max(res, sum);
        }
        return res;
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        vector<int> f(nums1.size() + 1, 0);
        for (int i = 0; i < nums1.size(); i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            f[i] = nums2[i] - nums1[i];
        }
        sum1 += sum(f);
        for (int i = 0; i < nums1.size(); i++)
            f[i] = nums1[i] - nums2[i];
        sum2 += sum(f);
        return max(sum1, sum2);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [60,60,60]\n[10,90,10]\n
// @lcpr case=end

// @lcpr case=start
// [20,40,20,70,30]\n[50,20,50,40,20]\n
// @lcpr case=end

// @lcpr case=start
// [7,11,13]\n[1,1,1]\n
// @lcpr case=end

 */

