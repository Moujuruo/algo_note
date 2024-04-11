/*
 * @lc app=leetcode.cn id=LCP 24 lang=cpp
 * @lcpr version=30113
 *
 * [LCP 24] 数字游戏
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
    static const int MOD = 1e9 + 7;
public:
    vector<int> numsGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> right;
        priority_queue<int> left;
        int n = nums.size();
        int leftsum = 0, rightsum = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int b = nums[i] - i;
            if (i % 2 == 0) {
                if (!left.empty() && b < left.top()) {
                    leftsum -= left.top();
                    leftsum += b;
                    left.push(b);
                    b = left.top();
                    left.pop();
                }
                right.push(b);
                rightsum += b;
                ans[i] = (((rightsum - leftsum - right.top())) % MOD);
            } 
            else {
                if (b > right.top()) {
                    rightsum -= right.top();
                    rightsum += b;
                    right.push(b);
                    b = right.top();
                    right.pop();
                }
                left.push(b);
                leftsum += b;
                ans[i] = ((rightsum - leftsum) % MOD);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,1,6,7]`>\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]`>\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3,4]`>\n
// @lcpr case=end

 */

