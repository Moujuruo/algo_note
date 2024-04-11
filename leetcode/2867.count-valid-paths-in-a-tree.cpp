/*
 * @lc app=leetcode.cn id=2867 lang=cpp
 * @lcpr version=30116
 *
 * [2867] 统计树中的合法路径数目
 */


// @lcpr-template-start
#include <numeric>
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
using ll = long long;
class Solution {
public:
    static const int N = 1e5 + 10;
    unordered_set<int> primes;
    int h[2 * N], e[2 * N], ne[2 * N], idx;
    int fa[N], counts[N];
    ll ret = 0;

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a];
        h[a] = idx++;
    }

    unordered_set<int> GetPrimes(int n) {
        vector<int> q(n + 1, 0);
        unordered_set<int> primes;
        for (int i = 2; i <= sqrt(n); i++) {
            if (q[i] == 1) continue;
            int j = i * 2;
            while (j <= n) {
                q[j] = 1;
                j += i;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (q[i] == 0) primes.insert(i);
        }
        return primes;
    }

    bool isPrime(int x) {
        return primes.count(x);
    }

    int find(int x) {
        if (x != fa[x]) fa[x] = find(fa[x]);
        return fa[x];
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        primes = GetPrimes(n);
        for (int i = 1; i <= n; i++)
            h[i] = -1, fa[i] = i, counts[i] = 1;
        for (auto& edge: edges) {
            int a = edge[0], b = edge[1];
            add(a, b);
            add(b, a);
            if (!isPrime(a) && !isPrime(b)) {
                int pa = find(a), pb = find(b);
                if (pa != pb) {
                    fa[pa] = pb;
                    counts[pb] += counts[pa];
                }
            }
        }
        for (int p: primes) {
            vector<ll> arr;
            for (int i = h[p]; ~i; i = ne[i]) {
                if (!isPrime(e[i])) {
                    arr.push_back(counts[find(e[i])]);
                }
            }
            ll sum = 0;
            ll tot = accumulate(arr.begin(), arr.end(), 0ll);
            for (ll x: arr) {
                sum += x * (tot - x);
            }
            ret += sum / 2 + tot;
        }
        return ret;
    }

};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[1,2],[1,3],[2,4],[2,5]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[1,2],[1,3],[2,4],[3,5],[3,6]]\n
// @lcpr case=end

 */

