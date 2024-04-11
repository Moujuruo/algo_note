// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=971 lang=cpp
 * @lcpr version=30121
 *
 * [971] 翻转二叉树以匹配先序遍历
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
    vector<int> ans;

    bool dfs(TreeNode* root, vector<int>& voyage, int& idx) {
        if (root == nullptr) return true;
        if (root->val != voyage[idx]) return false;
        idx++;
        if (root->left && root->left->val != voyage[idx]) {
            ans.push_back(root->val);
            swap(root->left, root->right);
        }
        return dfs(root->left, voyage, idx) && dfs(root->right, voyage, idx);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (root == nullptr) return {};
        int idx = 0;
        if (!dfs(root, voyage, idx)) return {-1};
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n[2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

 */

