#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    static const int N = 2e5 + 10;
    int p[N];
    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        // 思路是建立多个连通块，对于每个连通块维护一个weight，weight为连通块内所有边权按位与的结果
        // 对于每个查询，如果两个点在同一个连通块内，那么答案就是连通块内的weight
        // 如果不在同一个连通块内，就返回-1
        vector<int> weights(n, INT_MAX);
        for (auto& e: edges) {
            int a = e[0], b = e[1], c = e[2];
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                p[pa] = pb;
                weights[pb] &= weights[pa] & c;
            }
            else {
                weights[pb] &= c;
            }
        }
        vector<int> ans;
        for (auto& q: query) {
            int x = q[0], y = q[1];
            if (x == y) {
                ans.push_back(0);
                continue;
            }
            int px = find(x), py = find(y);
            if (px != py) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(weights[px]);
            }
        }
        return ans;

    }
};

int main() {
    Solution s;
    // n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]
    
    vector<int> ans = s.minimumCost(3, edges, query);
    for (auto& x: ans) {
        cout << x << " ";
    }
    cout << endl;
}