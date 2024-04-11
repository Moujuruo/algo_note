#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5e3 + 10, INF = 0x3f3f3f3f;
int n, m;
int dist[N], st[N];
int g[N][N];
int ans = -INF;

int prim() {
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (i && dist[t] == INF) return INF;
        if (i) res += dist[t], ans = max(ans, dist[t]);
        st[t] = 1;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main() {
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prim();

    if (t == INF) puts("-1");
    else printf("%d\n", ans);
    return 0;
}