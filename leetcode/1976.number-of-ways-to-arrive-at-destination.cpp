/*
 * @lc app=leetcode.cn id=1976 lang=cpp
 * @lcpr version=30117
 *
 * [1976] 到达目的地的方案数
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
class Solution {
public:
    using ll = long long;
    static const int N = 201, MOD = 1e9 + 7;
    int w[N][N];
    bool st[N];
    ll cnt[N];
    ll dist[N];
    int min_time;
    void dijkstra(int n) {
        memset(st, 0, sizeof st);
        for (int i = 0; i < n; i++) dist[i] = LLONG_MAX / 2;
        dist[0] = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            int t = -1;
            for (int j = 0; j < n; j++) 
                if (!st[j] && (t == -1 || dist[j] < dist[t]))   
                    t = j;
            st[t] = true;
            for (int j = 0; j < n; j++) {
                if (dist[j] > dist[t] + w[t][j]) {
                    dist[j] = dist[t] + w[t][j];
                    cnt[j] = cnt[t];
                } else if (dist[j] == dist[t] + w[t][j]) {
                    cnt[j] = (cnt[t] + cnt[j]) % MOD;
                }
            }

        }

    }

    int countPaths(int n, vector<vector<int>>& roads) {
        memset(w, 0x3f, sizeof w);
        for (auto &road: roads) {
            int a = road[0], b = road[1], c = road[2];
            w[a][b] = w[b][a] = c;
        }
        dijkstra(n);

        return cnt[n - 1];

    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0,10]]\n
// @lcpr case=end

 */

