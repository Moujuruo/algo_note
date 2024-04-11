/*
 * @lc app=leetcode.cn id=60 lang=cpp
 * @lcpr version=30119
 *
 * [60] 排列序列
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
    int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    bool used[10];
    int num[10];
    string t;
    int cnt = 0;
    void dfs(int idx, int n, int k) {
        if (idx == n) {
            cnt++;
            if (cnt == k) {
                for (int i = 0; i < n; i++) {
                    t += num[i] + '0';
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            if (cnt + fac[n - idx - 1] < k) {
                cnt += fac[n - idx - 1];
                continue;
            }
            used[i] = true;
            num[idx] = i;
            dfs(idx + 1, n, k);
            used[i] = false;
        }
    }

    string getPermutation(int n, int k) {
        dfs(0, n, k);
        return t;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n3\n
// @lcpr case=end

// @lcpr case=start
// 4\n9\n
// @lcpr case=end

// @lcpr case=start
// 3\n1\n
// @lcpr case=end

 */

