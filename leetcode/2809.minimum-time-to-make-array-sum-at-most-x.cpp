/*
 * @lc app=leetcode.cn id=2809 lang=cpp
 * @lcpr version=30113
 *
 * [2809] 使数组和小于等于 x 的最少时间
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
    static const int N = 1010;
    typedef pair<int, int> PII;
    typedef long long ll;
    vector<PII> arr;
    ll f[N][N];
    int S[N];
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            arr.push_back({nums1[i], nums2[i]});
        }
        sort(arr.begin(), arr.end(), [](const PII&a, const PII&b) {
            return a.second < b.second;
        });
        arr.insert(arr.begin(), {0, 0});
        for (int i = 1; i <= n; i++) {
            S[i] = S[i - 1] + arr[i].second;
        }
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (j >= 1)
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + S[i - 1]);
                f[i][j] = min(f[i][j], f[i - 1][j] + arr[i].first + arr[i].second * j);
            }
        }
        for (int i = 0; i <= n; i++) {
            if (f[n][i] <= x) return i;
        }
        return -1;
    } 
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[3,3,3]\n4\n
// @lcpr case=end

 */

