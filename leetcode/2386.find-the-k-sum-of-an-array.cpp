/*
 * @lc app=leetcode.cn id=2386 lang=cpp
 * @lcpr version=30118
 *
 * [2386] 找出数组的第 K 大和
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
    using PLI = pair<ll, int>;
    long long kSum(vector<int>& nums, int k) {
        ll ans = 0;
        for (int &x: nums) {
            if (x > 0)  ans += x;
            else x = -x;
        }
        if (k == 1) return ans;
        sort(nums.begin(), nums.end());
        priority_queue<PLI, vector<PLI>, greater<>> pq;
        pq.push({nums[0], 0});
        for (int i = 0; i < k - 1; i++) {
            auto [s, idx] = pq.top();
            pq.pop();
            if (i == k - 2) return ans - s;
            if (idx + 1 < nums.size()) {
                pq.push({s - nums[i] + nums[i + 1], idx + 1});
                pq.push({s + nums[i + 1], idx + 1});
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,-2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,-2,3,4,-10,12]\n16\n
// @lcpr case=end

 */

