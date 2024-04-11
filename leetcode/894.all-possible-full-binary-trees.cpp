/*
 * @lc app=leetcode.cn id=894 lang=cpp
 * @lcpr version=30121
 *
 * [894] 所有可能的真二叉树
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n == 1) {
            return {new TreeNode()};
        }
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        // vector<TreeNode*> res;
        // for (int i = 1; i < n; i += 2) {
        //     auto left = allPossibleFBT(i);
        //     auto right = allPossibleFBT(n - i - 1);
        //     for (auto l : left) {
        //         for (auto r : right) {
        //             res.push_back(new TreeNode(0, l, r));
        //         }
        //     }
        // }
        // return res;

        vector<TreeNode*> res;
        for (int i = 1; i < n; i += 2) {
            auto left = allPossibleFBT(i);
            auto right = allPossibleFBT(n - i - 1);
            for (auto l : left) {
                for (auto r : right) {
                    res.push_back(new TreeNode(0, l, r));
                }
            }
        }
        memo[n] = res;
        return res;


    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

