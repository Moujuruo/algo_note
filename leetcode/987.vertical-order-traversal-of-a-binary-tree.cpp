/*
 * @lc app=leetcode.cn id=987 lang=cpp
 * @lcpr version=30116
 *
 * [987] 二叉树的垂序遍历
 */


// @lcpr-template-start
#include <cstdint>
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
    using PII = pair<int, int>;
    map<int, vector<PII>> mp;
    void dfs(TreeNode* root, int x, int y) {
        if (!root) return;
        mp[x].push_back({y, root->val});
        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for (auto& [x, vec] : mp) {
            sort(vec.begin(), vec.end());
            vector<int> tmp;
            for (auto& [y, val] : vec) {
                tmp.push_back(val);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,6,5,7]\n
// @lcpr case=end

 */

