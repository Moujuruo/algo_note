/*
 * @lc app=leetcode.cn id=1997 lang=cpp
 * @lcpr version=30121
 *
 * [1997] 访问完所有房间的第一天
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
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long> s(n);
        for (int i = 0; i < n - 1; i++) {
            s[i + 1] = (s[i] + 2 + s[i] - s[nextVisit[i]] + 1000000007) % 1000000007;
        }
        return s[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,0]\n
// @lcpr case=end

 */

