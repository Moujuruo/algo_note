/*
 * @lc app=leetcode.cn id=2192 lang=cpp
 * @lcpr version=30121
 *
 * [2192] 有向无环图中一个节点的所有祖先
 */


// @lcpr-template-start
#include <set>
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
class Solution {
public:
    static const int N = 2020;
    int h[N], e[N], ne[N], idx;
    int enter[N];

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a];
        h[a] = idx++;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        memset(h, -1, sizeof h);
        for (auto &edge: edges) {
            add(edge[0], edge[1]);
            enter[edge[1]] ++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!enter[i]) {
                q.push(i);
            }
        }
        vector<set<int>> res(n);
        
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                for (auto x: res[t]) {
                    res[j].insert(x);
                }
                res[j].insert(t);
                enter[j] --;
                if (!enter[j]) {
                    q.push(j);
                }
            }

        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (auto x: res[i]) {
                tmp.push_back(x);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]\n
// @lcpr case=end

 */

