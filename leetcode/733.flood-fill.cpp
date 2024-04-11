/*
 * @lc app=leetcode.cn id=733 lang=cpp
 * @lcpr version=30117
 *
 * [733] 图像渲染
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
    const int dx[4] = {0, 0, 1, -1},
              dy[4] = {1, -1, 0, 0};
    bool used[51][51];
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        memset(used, 0, sizeof used);
        PII st = {sr, sc};
        int n = image.size();
        int ini_color = image[sr][sc];
        queue<PII> q;
        q.push(st);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for (int i = 0; i < 3; i++) {
                int tx = x + dx[i],
                    ty = y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                if (!used[tx][ty] && image[tx][ty] == ini_color) {
                    image[tx][ty] = color;
                    used[tx][ty] = true;
                    q.push({tx, ty});
                }
            }
        }
        return image;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1],[1,1,0],[1,0\n1\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,0,0]]\n0\n0\n2\n
// @lcpr case=end

 */

