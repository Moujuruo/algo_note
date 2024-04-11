/*
 * @lc app=leetcode.cn id=LCP 30 lang=cpp
 * @lcpr version=30116
 *
 * [LCP 30] 魔塔游戏
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
    static const int N = 1e5 + 100;
    int h[N], size = 0;
    // 小根堆
    void down(int u) {
        int t = u;
        if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
        if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
        if (u != t) {
            swap(h[u], h[t]);
            down(t);
        }
    }
    void up(int u) {
        while (u / 2 && h[u / 2] > h[u]) {
            swap(h[u], h[u / 2]);
            u >>= 1;
        }
    }
    int magicTower(vector<int>& nums) {
        int n = nums.size();
        int tot = 1, ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                h[++size] = nums[i];
                up(size);
                tot += nums[i];
                while (tot < 0) {
                    tot -= h[1];
                    ans ++;
                    h[1] = h[size--];
                    down(1);
                }
            }
        }
        return ans;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [100,100,100,-250,-60,-140,-50,-50,100,150]`>\n
// @lcpr case=end

// @lcpr case=start
// [-200,-300,400,0]`>\n
// @lcpr case=end

 */

