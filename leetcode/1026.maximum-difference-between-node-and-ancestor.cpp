/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 * @lcpr version=30121
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int ans = 0;
    void dfs(TreeNode* root, int minv = INT_MAX, int maxv = INT_MIN) {
        if (root == nullptr) return;
        minv = min(minv, root->val);
        maxv = max(maxv, root->val);
        ans = max(ans, max(abs(root->val - minv), abs(root->val - maxv)));
        dfs(root->left, minv, maxv);
        dfs(root->right, minv, maxv);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,3,10,1,6,null,14,null,null,4,7,13]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,null,0,3]\n
// @lcpr case=end

 */

