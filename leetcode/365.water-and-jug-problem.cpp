/*
 * @lc app=leetcode.cn id=365 lang=cpp
 * @lcpr version=30113
 *
 * [365] 水壶问题
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
   unordered_set<long long> visited;
    int x, y, z;

    bool dfs(int a, int b) {
        long long state = ((long long)a << 32) | b;
        if (visited.count(state)) return false;
        if (a == z || b == z || a + b == z) return true;

        visited.insert(state);

        // Fill jug1
        if (dfs(x, b)) return true;
        // Fill jug2
        if (dfs(a, y)) return true;
        // Empty jug1
        if (dfs(0, b)) return true;
        // Empty jug2
        if (dfs(a, 0)) return true;
        // Pour jug1 to jug2
        int pour = min(a, y - b);
        if (dfs(a - pour, b + pour)) return true;
        // Pour jug2 to jug1
        pour = min(x - a, b);
        if (dfs(a + pour, b - pour)) return true;

        return false;
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        x = jug1Capacity;
        y = jug2Capacity;
        z = targetCapacity;
        return dfs(0, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n5\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n3\n
// @lcpr case=end

 */

