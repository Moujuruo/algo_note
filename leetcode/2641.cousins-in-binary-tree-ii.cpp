/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 * @lcpr version=30116
 *
 * [2641] 二叉树的堂兄弟节点 II
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
    static const int N = 4e5 + 10;
    TreeNode *q[N], *temp[2];
    int hh = 0, tt = -1, ptr = 0;
    TreeNode* replaceValueInTree(TreeNode* root) {
        int len = 1;
        q[++tt] = root;
        q[++tt] = NULL;
        while (hh <= tt) {
            int pair_nums = len, sum = 0;
            len = 0;
            // auto t = q[hh++];
            for (int i = 0, j = 0; i < pair_nums; j++) {
                auto t = q[hh + j];
                if (t) {
                    sum += t->val;
                }
                else {
                    i++;
                }
            }
            int pair_sum = 0;
            for (int i = 0; i < pair_nums; ) {
                auto t = q[hh++];
                if (t) {
                    if (t->left) q[++tt] = t->left;
                    if (t->right) q[++tt] = t->right;
                    q[++tt] = NULL;
                    temp[ptr++] = t;
                    pair_sum += t->val;
                    len++;
                }
                else {
                    int new_val = sum - pair_sum;
                    for (int j = 0; j < ptr; j++) {
                        temp[j]->val = new_val;
                    }
                    ptr = 0;
                    i++;
                    pair_sum = 0;
                }
            }
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,9,1,10,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n
// @lcpr case=end

 */

