/*
 * @lc app=leetcode.cn id=2059 lang=cpp
 * @lcpr version=30122
 *
 * [2059] 转化数字的最小运算数
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
    int minimumOperations(vector<int>& nums, int start, int goal) {
        // 双向bfs
        queue<int> q1, q2;
        unordered_map<int, int> dist1, dist2;
        q1.push(start);
        q2.push(goal);
        dist1[start] = 0;
        dist2[goal] = 0;
        bool flag = true; // true: q1, false: q2
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) {
                swap(q1, q2), swap(dist1, dist2);
                flag = !flag;
            }
            int u = q1.front();
            q1.pop();
            if (flag && (u < 0 || u > 1000)) continue;
            for (int i = 0; i < nums.size(); i++) {
                if (flag) {
                    for (auto v: {u + nums[i], u - nums[i], u ^ nums[i]}) {
                        if (dist1.count(v)) continue;
                        dist1[v] = dist1[u] + 1;
                        q1.push(v);
                        if (dist2.count(v)) return dist1[v] + dist2[v];
                    }
                }
                else {
                    for (auto v: {u + nums[i], u - nums[i], u ^ nums[i]}) {
                        if (v < 0 || v > 1000) continue;
                        if (dist1.count(v)) continue;
                        dist1[v] = dist1[u] + 1;
                        q1.push(v);
                        if (dist2.count(v)) return dist1[v] + dist2[v];
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,12]\n2\n12\n
// @lcpr case=end

// @lcpr case=start
// [3,5,7]\n0\n-4\n
// @lcpr case=end

// @lcpr case=start
// [2,8,16]\n0\n1\n
// @lcpr case=end

 */

