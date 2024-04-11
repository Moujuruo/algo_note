/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 * @lcpr version=30113
 *
 * [1514] 概率最大的路径
 */


// @lcpr-template-start
#include <cmath>
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
    static const int N = 2e6 + 10;
    int e[N], ne[N], h[N], idx;
    double w[N], dist[N];
    bool st[N];
public:
    void add(int a, int b, double c) {
        e[idx] = b, w[idx] = -log2(c);
        ne[idx] = h[a];
        h[a] = idx ++;
    }
    double spfa(int s, int ed) {
        for (int i = 0; i < N; i++)
            dist[i] = (double)0x3f3f3f3f;
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        st[s] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            st[t] = false;
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                if (dist[j] > dist[t] + w[i]) {
                    dist[j] = dist[t] + w[i];
                    if (!st[j]) {
                        st[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        // if (dist[ed] == (double)0x3f3f3f3f) return -1;
        // else 
        return dist[ed];

    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int len = succProb.size();
        memset(h, -1, sizeof h);
        for (int i = 0; i < len; i++) {
            int a = edges[i][0],
                b = edges[i][1];
            double c = succProb[i];
                add(a, b, c);
                add(b, a, c);
        }
        double k = spfa(start_node, end_node);
        return k == -1 ? 0 : pow(2, -k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.2]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.3]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1]]\n[0.5]\n0\n2\n
// @lcpr case=end

 */

