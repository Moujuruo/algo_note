// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1366 lang=cpp
 * @lcpr version=30120
 *
 * [1366] 通过投票对团队排名
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
    vector<int> cnt[26];

    string rankTeams(vector<string>& votes) {
        if (votes.size() == 1) return votes[0];
        int n = votes[0].size();
        for (int i = 0; i < 26; i++) {
            cnt[i].resize(n + 1);
            cnt[i][n] = i;
        }
        for (auto vote: votes) {
            for (int i = 0; i < n; i++) {
                cnt[vote[i] - 'A'][i]++;
            }
        }
        sort(cnt, cnt + 26, [](const vector<int>& a, const vector<int>& b) {
            for (int i = 0; i < a.size() - 1 ; i++) {
                if (a[i] != b[i]) return a[i] > b[i];
            }
            return a.back() < b.back();
        });
        string res;
        for (int i = 0; i < n; i++) {
            res.push_back('A' + cnt[i].back());
        }
        return res;

    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=rankTeams
// paramTypes= ["string[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// ["ABC","ACB","ABC","ACB","ACB"]\n
// @lcpr case=end

// @lcpr case=start
// ["WXYZ","XYZW"]\n
// @lcpr case=end

// @lcpr case=start
// ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]\n
// @lcpr case=end

// @lcpr case=start
// ["BCA","CAB","CBA","ABC","ACB","BAC"]\n
// @lcpr case=end

// @lcpr case=start
// ["M","M","M","M"]\n
// @lcpr case=end

 */

