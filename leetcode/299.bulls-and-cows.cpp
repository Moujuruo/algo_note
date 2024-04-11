/*
 * @lc app=leetcode.cn id=299 lang=cpp
 * @lcpr version=30118
 *
 * [299] 猜数字游戏
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
    unordered_map<char, int> cnt;
    string getHint(string secret, string guess) {
        for(char c: secret)
            cnt[c]++;
        int size = secret.size();
        int a = 0, b = 0;
        for (int i = 0; i < size; i++) {
            if (secret[i] == guess[i]) {
                a++;
                cnt[secret[i]]--;
            }
        }
        for (int i = 0; i < size; i++) {
            if (secret[i] != guess[i] && cnt[guess[i]]) {
                b++;
                cnt[guess[i]]--;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1807"\n"7810"\n
// @lcpr case=end

// @lcpr case=start
// "1123"\n"0111"\n
// @lcpr case=end

 */

