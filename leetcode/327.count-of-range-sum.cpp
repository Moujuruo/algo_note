/*
 * @lc app=leetcode.cn id=327 lang=cpp
 * @lcpr version=30113
 *
 * [327] 区间和的个数
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
    vector<int> alls;
    typedef long long ll;
    static const int N = 100010;

    int n, tr[N], s[N];

    int lowbit(int x) {
        return x & -x;
    }

    int sum(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i))
            ans += tr[i];
        return ans;
    }

    void add(int x, int val) {
        for (int i = x; i <= alls.size(); i += lowbit(i))
            tr[i] += val;
    }

    int findx(int x) {
        int l = 0, r = alls.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (alls[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return l + 1;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int tot = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            if (nums[i] >= lower && nums[i] <= upper)
                tot ++;
            s[i] = s[i - 1] + nums[i];
            alls.push_back(s[i]);
            alls.push_back(s[i] - upper);
            alls.push_back(s[i] - lower);
        }
        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());
        for (int i = 1; i <= n; i++) {
            int j = s[i];
            int l = findx(j - upper) - 1, r = findx(j - lower);
            // printf("%d %d %d %d\n", j, l + 1, r, findx(j));
            tot += sum(r) - sum(l);
            // printf("sumr: %d suml: %d\n", sum(r), sum(l));
            add(findx(j), 1);
        }
        return tot;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,5,-1]\n-2\n2\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n0\n
// @lcpr case=end

 */

