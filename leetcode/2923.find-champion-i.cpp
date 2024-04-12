/*
 * @lc app=leetcode.cn id=2923 lang=cpp
 * @lcpr version=30122
 *
 * [2923] 找到冠军 I
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
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        bool flag = true;
        for (int i = 0; i < n; i++) {
            flag = true;
            for (int j = 0; j < n; j++)
                if (i == j)
                    continue;
                else {
                    if (grid[i][j] == 0) {
                        flag = false;
                        break;
                    }
                }
            if (flag)
                return i;
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,1],[1,0,1],[0,0,0]]\n
// @lcpr case=end

 */

