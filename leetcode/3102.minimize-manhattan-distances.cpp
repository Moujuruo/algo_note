/*
 * @lc app=leetcode.cn id=3102 lang=cpp
 * @lcpr version=30121
 *
 * [3102] 最小化曼哈顿距离
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
    using PII = pair<int, int>;
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        int ans = INT_MAX;
        int max_newx_idx = -1, min_newx_idx = -1;
        int max_newy_idx = -1, min_newy_idx = -1;

        // ban 表示移除的点
        auto cal = [&](int ban) {
            int max_new_x = INT_MIN, min_new_x = INT_MAX;
            int max_new_y = INT_MIN, min_new_y = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (i == ban) continue;
                // 转为切比雪夫距离
                int new_X = points[i][0] + points[i][1];
                int new_Y = points[i][0] - points[i][1];
                if (new_X > max_new_x) {
                    max_new_x = new_X;
                    max_newx_idx = i;
                }
                if (new_X < min_new_x) {
                    min_new_x = new_X;
                    min_newx_idx = i;
                }
                if (new_Y > max_new_y) {
                    max_new_y = new_Y;
                    max_newy_idx = i;
                }
                if (new_Y < min_new_y) {
                    min_new_y = new_Y;
                    min_newy_idx = i;
                }
            }
            if (ban == -1) return ;
            int d = max(max_new_x - min_new_x, max_new_y - min_new_y);
            ans = min(ans, d);
        };

        cal(-1);
        cal(max_newx_idx);
        cal(min_newx_idx);
        cal(max_newy_idx);
        cal(min_newy_idx);

        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,10],[5,15],[10,2],[4,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1],[1,1]]\n
// @lcpr case=end

 */

