/*
 * @lc app=leetcode.cn id=662 lang=cpp
 * @lcpr version=30119
 *
 * [662] 二叉树最大宽度
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
    unordered_map<int, long long> leftmost;
    long long ans = 0;

    void dfs(TreeNode* Node, long long u, int d) {
        if (Node == NULL) return ;
        if (leftmost.count(d) == 0) {
            leftmost[d] = u; // 第一次访问到的是最左边的
        }
        ans = max(ans, u - leftmost[d] + 1);
        u = u - leftmost[d] + 1;
        dfs(Node->left, u * 2, d + 1);
        dfs(Node->right, u * 2 + 1, d + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 1, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,5,3,null,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5,null,null,9,6,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5]\n
// @lcpr case=end

 */

