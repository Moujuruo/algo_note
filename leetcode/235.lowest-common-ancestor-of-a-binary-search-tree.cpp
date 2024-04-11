/*
 * @lc app=leetcode.cn id=235 lang=cpp
 * @lcpr version=30116
 *
 * [235] 二叉搜索树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<TreeNode*>> fa;

    unordered_map<int, int> depth;
    
    void bfs(TreeNode* root) {
        if (root != NULL) depth[root->val] = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t->left) {
                depth[t->left->val] = depth[t->val] + 1;
                fa[t->left->val][0] = t;
                q.push(t->left);
                for (int k = 1; k <= 15; k++)
                    fa[t->left->val][k] = fa[fa[t->left->val][k - 1]->val][k - 1];
            }
            if (t->right) {
                depth[t->right->val] = depth[t->val] + 1;
                fa[t->right->val][0] = t;
                q.push(t->right);
                for (int k = 1; k <= 15; k++)
                    fa[t->right->val][k] = fa[fa[t->right->val][k - 1]->val][k - 1];
            }
        }
    }

    TreeNode* lca(TreeNode* p, TreeNode* q) {
        if (depth[p->val] < depth[q->val]) swap(p, q);
        for (int k = 15; k >= 0; k--)
            if (depth[fa[p->val][k]->val] >= depth[q->val]) p = fa[p->val][k];
        if (p->val == q->val) return p;
        for (int k = 15; k >= 0; k--) {
            if (fa[p->val][k]->val != fa[q->val][k]->val) {
                p = fa[p->val][k];
                q = fa[q->val][k];
            }
        }
        return fa[p->val][0];
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa = vector<vector<TreeNode*>>(N, vector<TreeNode*>(16));
        bfs(root);
        return lca(p, q);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

 */

