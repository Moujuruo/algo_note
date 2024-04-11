/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 * @lcpr version=30121
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
 */


// @lcpr-template-start
#include <type_traits>
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
    TreeNode* LCA(TreeNode* root, int s, int d) {
        if (root == NULL) return nullptr;
        if (root->val == s || root->val == d) return root;
        TreeNode* left = LCA(root->left, s, d);
        TreeNode* right = LCA(root->right, s, d);
        if (left && right) return root;
        return left ? left : right;
    }

    bool dfs(TreeNode* root, int s, string& path) {
        if (root == NULL) return false;
        if (root->val == s) return true;
        // if (dfs(root->left, s, path + 'L')) return true;
        // if (dfs(root->right, s, path + 'R')) return true;
        path += 'L';
        if (dfs(root->left, s, path)) return true;
        path.pop_back();
        path += 'R';
        if (dfs(root->right, s, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);
        string path;
        dfs(lca, startValue, path);
        for (int i = 0; i < path.size(); i++) {
            path[i] = 'U';
        }

        string path2;
        dfs(lca, destValue, path2);
        return path + path2;

        
        
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,1,2,3,null,6,4]\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n1\n
// @lcpr case=end

 */

