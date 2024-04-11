/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 * @lcpr version=30118
 *
 * [1261] 在受污染的二叉树中查找元素
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
class FindElements {
public:
    unordered_set<int> nodes;
    void recover(TreeNode* root) {
        if (root == NULL) return ;
        if (root->left != NULL) {
            root->left->val = root->val * 2 + 1;
            nodes.insert(root->left->val);
            recover(root->left);
        }
        if (root->right != NULL) {
            root->right->val = root->val * 2 + 2;
            nodes.insert(root->right->val);
            recover(root->right);
        }
    }

    FindElements(TreeNode* root) {
        root->val = 0;
        nodes.insert(0);
        recover(root);
    }
    
    bool find(int target) {
        return nodes.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end



/*
// @lcpr case=start
// ["FindElements","find","find"][[[-1,null,-1]],[1],[2]]\n
// @lcpr case=end

// @lcpr case=start
// ["FindElements","find","find","find"][[[-1,-1,-1,-1,-1]],[1],[3],[5]]\n
// @lcpr case=end

// @lcpr case=start
// ["FindElements","find","find","find","find"][[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]\n
// @lcpr case=end

 */

