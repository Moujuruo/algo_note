/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=30116
 *
 * [124] 二叉树中的最大路径和
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
    int ans = -INT_MAX;
    int dfs(TreeNode *u) {
        if (u == NULL) return 0;
        int l = dfs(u->left);
        int r = dfs(u->right);
        ans = max(ans, l + r + u->val);

        int sum = max(l, max(r, 0)) + u->val;
        return sum < 0 ? 0 : sum;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */

