/*
 * @lc app=leetcode.cn id=2580 lang=cpp
 * @lcpr version=30120
 *
 * [2580] 统计将重叠区间合并成组的方案数
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
    const int N = 1e9 + 7;
    using ll = long long;

    int cnt = 0;

    void merge(vector<vector<int>>& ranges) {
        int st = -1, ed = -1;
        for (auto &r: ranges) {
            if (r[0] > ed) {
                if (st != -1) {
                    cnt ++;
                }
                st = r[0];
                ed = r[1];
            }
            else {
                ed = max(ed, r[1]);
            }
        }
    }

    int fast_pow(int a, int b, int mod) {
        if (b == 0) return 1;
        if (b % 2 == 0) {
            ll t = fast_pow(a, b / 2, mod);
            return t * t % mod;
        } else {
            return a * fast_pow(a, b - 1, mod) % mod;
        }
    }

    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        merge(ranges);
        // return (1 << (cnt + 1)) % N;
        return fast_pow(2, cnt + 1, N);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[6,10],[5,15]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[10,20],[2,5],[4,8]]\n
// @lcpr case=end

 */

