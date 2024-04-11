#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

const int N = 1e6 + 10;
typedef pair<int, int> PII;

int T;
int h[N], ne[N], e[N], idx;
int p[N], st[N];
int res[N];
int n, m;
vector<PII> query[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a];
    h[a] = idx++;
}

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

// tarjan 算法求 LCA
void tarjan(int u) {
    st[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            tarjan(j);
            p[j] = u;
        }
    }
    for (auto item: query[u]) {
        int y = item.first, id = item.second;
        if (st[y]) {
            res[id] = find(y);
        }
    }
    st[u] = 2;
}

int main() {
    scanf("%d", &T);
    for (int l = 1; l <= T; l++) {
        memset(h, -1, sizeof h);
        memset(st, 0, sizeof st);
        memset(res, 0, sizeof res);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            scanf("%d", &m);
            for (int j = 1; j <= m; j++) {
                int x;
                scanf("%d", &x);
                add(i, x);
                add(x, i);
            }
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            query[a].push_back({b, i});
            query[b].push_back({a, i});
        }
        tarjan(1);
        printf("Case %d:\n", l);
        for (int i = 1; i <= m; i++) {
            printf("%d\n", res[i]);
        }
    }
    return 0;
}