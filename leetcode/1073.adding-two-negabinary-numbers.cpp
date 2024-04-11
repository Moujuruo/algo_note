/*
 * @lc app=leetcode.cn id=1073 lang=cpp
 * @lcpr version=30121
 *
 * [1073] 负二进制数相加
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
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        if (arr1.size() < arr2.size()) swap(arr1, arr2);
        int n = arr1.size(), m = arr2.size();
        vector<int> arr;
        bool flag = true;
        int k = 0;
        for (int i = 0; i < m; i++) {
            int tot = arr1[i] + arr2[i] + k;
            k = 0;
            if (tot % 2 == 0) {
                arr.push_back(0);
                if (tot == 2) {
                    if (i % 2 == 0)
                        k = -1;
                    else
                        k = 1;
                }
            }
            else {
                arr.push_back(1);
                flag = false;
                if (tot == 3) {
                    if (i % 2 == 0)
                        k = -1;
                    else
                        k = 1;
                }
            }
        }
        for (int i = m; i < n; i++) {
            int tot = arr1[i] + k;
            k = 0;
            if (tot % 2 == 0) {
                arr.push_back(0);
                if (tot == 2) {
                    if (i % 2 == 0)
                        k = -1;
                    else
                        k = 1;
                }
            }
            else {
                arr.push_back(1);
                flag = false;
                if (tot == 3) {
                    if (i % 2 == 0)
                        k = -1;
                    else
                        k = 1;
                }
            }
        }
        if (k != 0) {
            arr.push_back(1);
            arr.push_back(1);
        }
        if (flag && !k) {
            vector<int> tmp(1, 0);
            return tmp;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,1,1]\n[1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[1]\n
// @lcpr case=end

 */

