/*
 * @lc app=leetcode.cn id=1483 lang=cpp
 * @lcpr version=30121
 *
 * [1483] 树节点的第 K 个祖先
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
class TreeAncestor {
public:
    static const int N = 1e5 + 10;
    int fa[N][17];
    int h[N], ne[N], e[N], idx;
    int f[N][17];
    int root = 0;

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }


    TreeAncestor(int n, vector<int>& parent) {
        memset(h, -1, sizeof h);
        memset(fa, -1, sizeof fa);
        for (int i = 0; i < n; i++) {
            fa[i][0] = parent[i];
            if (parent[i] == -1) {
                root = i;
            } else {
                add(parent[i], i);
            }
        }
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                fa[j][0] = t;
                q.push(j);
                for (int k = 1; k <= 16; k++) {
                    if (fa[j][k - 1] == -1) {
                        fa[j][k] = -1;
                    } else {
                        fa[j][k] = fa[fa[j][k - 1]][k - 1];
                    }
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 16; i >= 0; i--) {
            if (k >= (1 << i)) {
                node = fa[node][i];
                if (node == -1) {
                    return -1;
                }
                k -= (1 << i);
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end



/*
// @lcpr case=start
// ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"][[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]\n
// @lcpr case=end

 */

