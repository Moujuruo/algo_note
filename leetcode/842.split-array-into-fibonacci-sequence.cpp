/*
 * @lc app=leetcode.cn id=842 lang=cpp
 * @lcpr version=30121
 *
 * [842] 将数组拆分成斐波那契序列
 */


// @lcpr-template-start
#include <string>
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
    vector<int> ans;
    int len;

    int CalBitCnt(int t) {
        int k = 0;
        while (t > 0) {
            t /= 10;
            k ++;
        }
        return k;
    }

    bool dfs(string num, int idx) {
        int target = -1, bit_cnt = -1;
        if (ans.size() > 2) {
            target = ans[ans.size() - 2] + ans[ans.size() - 1];
            bit_cnt = CalBitCnt(target);
            if (ans.back() != ans[ans.size() - 2] + ans[ans.size() - 3]) 
                return false;
        }
        if (idx >= len) {
            if (ans.size() < 3)
                return false;
            else 
                return true;
        }
        if (num[idx] == '0') {
            ans.push_back(0);
            if (!dfs(num, idx + 1)) {
                ans.pop_back();
                return false;
            }
            else
                return true;
        }
        long long k = 0;
        for (int i = 1; i <= len / 3 + 1; i++) {
            if (idx + i > len)
                break;
            string sub = num.substr(idx, i);
            k = stoll(sub);
            if (target == -1) {
                ans.push_back(k);
                if (!dfs(num, idx + i)) {
                    ans.pop_back();
                }
                else 
                    return true;
            }
            else {
                if (k != target) continue;
                if (i > bit_cnt) return false;
                ans.push_back(target);
                if (!dfs(num, idx + bit_cnt))
                    return false;
                else
                    return true;
            }
        }
        if (k != target) {
            return false;
        }
        
        
        return true;
    }

    vector<int> splitIntoFibonacci(string num) {
        len = num.size();
        bool flag = dfs(num, 0);
        vector<int> nul;
        return flag ? ans : nul;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1101111"\n
// @lcpr case=end

// @lcpr case=start
// "112358130"\n
// @lcpr case=end

// @lcpr case=start
// "0123"\n
// @lcpr case=end

 */

