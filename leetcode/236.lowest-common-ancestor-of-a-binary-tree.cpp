/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30116
 *
 * [236] 二叉树的最近公共祖先
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
    static const int N = 2 + 10;
    int cnt = 0;
    unordered_map<int, int> mp;
    int depth[N], fa[N][20];

    void bfs(TreeNode* root) {
        memset(depth, 0x3f, sizeof depth);
        depth[0] = 0, depth[mp[root->val]] = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (t->left){
                if(!mp.count(t->left->val)) mp[t->left->val] = ++cnt;
                int v = mp[t->left->val], u = mp[t->val];
                if (depth[v] > depth[u] + 1) {
                    depth[v] = depth[u] + 1;
                    fa[v][0] = u;
                    q.push(t->left);
                    for (int k = 1; k <= 19; k++)
                        fa[v][k] = fa[fa[v][k - 1]][k - 1];
                }
            }
            if (t->right) {
                if(!mp.count(t->right->val)) mp[t->right->val] = ++cnt;
                int v = mp[t->right->val], u = mp[t->val];
                if (depth[v] > depth[u] + 1) {
                    depth[v] = depth[u] + 1;
                    fa[v][0] = u;
                    q.push(t->right);
                    for (int k = 1; k <= 19; k++)
                        fa[v][k] = fa[fa[v][k - 1]][k - 1];
                }
            }
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        for (int k = 19; k >= 0; k--)
            if (depth[fa[a][k]] >= depth[b]) a = fa[a][k];
        if (a == b) return a;
        for (int k = 19; k >= 0; k--) {
            if (fa[a][k] != fa[b][k]) {
                a = fa[a][k];
                b = fa[b][k];
            }
        }
        return fa[a][0];
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!mp.count(root->val)) mp[root->val] = ++cnt;
        depth[0] = 0; depth[mp[root->val]] = 1;
        bfs(root);
        return new TreeNode(lca(mp[p->val], mp[q->val]));

    }
};

// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

