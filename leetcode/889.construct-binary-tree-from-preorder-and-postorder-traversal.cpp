/*
 * @lc app=leetcode.cn id=889 lang=cpp
 * @lcpr version=30116
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return root;
        int i = 0;
        for (int j = 0; j < postorder.size(); j++) {
            if (postorder[j] == preorder[1]) {
                i = j + 1;
                break;
            }
        }
        vector<int> left_pre(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> left_post(postorder.begin(), postorder.begin() + i);
        vector<int> right_pre(preorder.begin() + i + 1, preorder.end());
        vector<int> right_post(postorder.begin() + i, postorder.end() - 1);
        root->left = constructFromPrePost(left_pre, left_post);
        root->right = constructFromPrePost(right_pre, right_post);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1]\n
// @lcpr case=end

 */

