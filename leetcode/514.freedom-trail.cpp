/*
 * @lc app=leetcode.cn id=514 lang=cpp
 * @lcpr version=30113
 *
 * [514] 自由之路
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
    typedef pair<int, int> PII;
    static const int N = 2e5 + 10;
public:
    int hh = 0, tt = -1;
    PII q[N];
    int findRotateSteps(string ring, string key) {
        int len1 = ring.size();
        int len2 = key.size();
        int f[len1 + 1][len2 + 1];
        memset(f, -1, sizeof f);
        f[0][0] = 0;
        q[++tt] = {0, 0};
        while (hh <= tt) {
            auto p = q[hh++];
            int p1 = p.first, p2 = p.second;

            if (p2 == len2) {
                return f[p1][p2];
            }

            if (ring[p1] == key[p2]) {
                if (f[p1][p2 + 1] == -1) {
                    f[p1][p2 + 1] = f[p1][p2] + 1;
                    q[++tt] = {p1, p2 + 1};
                }
            }

            int right = (p1 + 1) % len1;
            if (f[right][p2] == -1) {
                f[right][p2] = f[p1][p2] + 1;
                q[++tt] = {right, p2};
            }
            
            int left = (p1 - 1 + len1) % len1;
            if (f[left][p2] == -1) {
                f[left][p2] = f[p1][p2] + 1;
                q[++tt] = {left, p2};
            }
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "godding"\n"gd"\n
// @lcpr case=end

// @lcpr case=start
// "godding"\n"godding"\n
// @lcpr case=end

 */

