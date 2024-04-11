/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 * @lcpr version=30116
 *
 * [2583] 二叉树中的第 K 大层和
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

    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>> p;
        queue<TreeNode*> q;
        if (root == NULL) return (long long)-1;
        q.push(root);
        int level_num = 0;
        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                sum += t->val;
            }
            level_num++;
            p.push(sum);
        }
        if (k > level_num) return (long long)-1;
        for (int i = 0; i < k - 1; i++) {
            p.pop();
        }
        return p.top();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,8,9,2,1,3,7,4,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,null,3]\n1\n
// @lcpr case=end

 */

