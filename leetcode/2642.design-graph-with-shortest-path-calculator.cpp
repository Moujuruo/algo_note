/*
 * @lc app=leetcode.cn id=2642 lang=cpp
 * @lcpr version=30120
 *
 * [2642] 设计可以求最短路径的图类
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
class Graph {
public:
    static const int N = 20001;
    int h[N], e[N], ne[N], w[N], idx = 0;
    void add(int a, int b, int c) {
        e[idx] = b, w[idx] = c;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    Graph(int n, vector<vector<int>>& edges) {
        memset(h, -1, sizeof h);
        for (auto edge: edges) {
            add(edge[0], edge[1], edge[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        add(edge[0], edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        int dist[N];
        memset(dist, 0x3f, sizeof dist);
        queue<int> q;
        bool st[N];
        memset(st, 0, sizeof st);
        dist[node1] = 0;
        q.push(node1);
        st[node1] = 1;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            st[t] = false;
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] > dist[t] + w[i]) {
                    dist[j] = dist[t] + w[i];
                    if (!st[j]) {
                        q.push(j);
                        st[j] = true;
                    }
                }
            }
        }
        return dist[node2] == 0x3f3f3f3f ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end



/*
// @lcpr case=start
// ["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"][[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]\n
// @lcpr case=end

 */

