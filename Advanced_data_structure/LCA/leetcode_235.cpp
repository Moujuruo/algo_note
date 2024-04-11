#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    static const int N = 1e6 + 10;
    vector<vector<TreeNode*>> fa;
    unordered_map<int, int> depth;

    Solution() {
    fa = vector<vector<TreeNode*>>(N, vector<TreeNode*>(16));
    }
    
    void bfs(TreeNode* root) {
        if (root != NULL) depth[root->val] = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            cout << "t->val: " << t->val << endl;
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
        if (p == q) return p;
        for (int k = 15; k >= 0; k--) {
            if (fa[p->val][k] != fa[q->val][k]) {
                p = fa[p->val][k];
                q = fa[q->val][k];
            }
        }
        return fa[p->val][0];
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bfs(root);
        cout << "finished bfs" << endl; // "finished bfs" will be printed out
        return lca(p, q);
    }

    // Function to build tree from a level-order input
    TreeNode* buildTree(const vector<int> &nodes) {
        if (nodes.empty() || nodes[0] == -1) return nullptr; // -1 indicates nullptr for this example
        vector<TreeNode*> nodePtrs;
        for (int val : nodes) {
            nodePtrs.push_back(val != -1 ? new TreeNode(val) : nullptr);
        }
        queue<TreeNode*> q;
        q.push(nodePtrs[0]);
        size_t idx = 1;
        while (!q.empty() && idx < nodePtrs.size()) {
            TreeNode* node = q.front(); q.pop();
            if (idx < nodePtrs.size() && node != nullptr) {
                node->left = nodePtrs[idx++];
                if (node->left) q.push(node->left);
            }
            if (idx < nodePtrs.size() && node != nullptr) {
                node->right = nodePtrs[idx++];
                if (node->right) q.push(node->right);
            }
        }
        return nodePtrs[0];
    }
};

TreeNode* findNode(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left != nullptr) return left;
    return findNode(root->right, val);
}

int main() {
    cout << "leetcode 235: Lowest Common Ancestor of a Binary Search Tree" << endl;
    vector<int> values = {6,2,8,0,4,7,9,-1,-1,3,5}; // -1 indicates nullptr here
    int pVal = 2, qVal = 8;
    cout << "values: [";
    Solution sol;
    cout << "Building tree..." << endl;
    TreeNode* root = sol.buildTree(values);
    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);
    cout << "p->val: " << p->val << ", q->val: " << q->val << endl;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca) cout << "Lowest Common Ancestor: " << lca->val << endl;
    else cout << "No LCA found." << endl;
    return 0;
}
