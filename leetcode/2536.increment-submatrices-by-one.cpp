/*
 * @lc app=leetcode.cn id=2536 lang=cpp
 * @lcpr version=30113
 *
 * [2536] 子矩阵元素加 1
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
    int b[502][502];
    void insert(int x1, int y1, int x2, int y2) {
        b[x1][y1] += 1;
        b[x2 + 1][y1] -= 1;
        b[x1][y2 + 1] -= 1;
        b[x2 + 1][y2 + 1] += 1;
    }

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                b[i][j] = 0;
        for (auto &q : queries) {
            insert(q[0] + 1, q[1] + 1, q[2] + 1, q[3] + 1);
        }
        vector<vector<int>> res(queries.size());
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                ans[i][j] = b[i + 1][j + 1];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[1,1,2,2],[0,0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,0,1,1]]\n
// @lcpr case=end

 */

