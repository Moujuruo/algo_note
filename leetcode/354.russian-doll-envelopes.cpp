/*
 * @lc app=leetcode.cn id=354 lang=cpp
 * @lcpr version=30120
 *
 * [354] 俄罗斯套娃信封问题
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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = envelopes.size();
        int piles = 0;
        vector<int> dp(n, 1);
        vector<int> top(n);
        for (int i = 0; i < n; i++) {
            int l = 0, r = piles;
            while (l < r) {
                int mid = (l + r) >> 1;
                // 寻找左侧边界
                if (top[mid] >= envelopes[i][1]) r = mid;
                else l = mid + 1;
            }
            if (l == piles) piles++;
            top[l] = envelopes[i][1];
        } 
        return piles;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[5,4],[6,4],[6,7],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1],[1,1]]\n
// @lcpr case=end

 */

