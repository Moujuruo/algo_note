#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2e3 + 10, M = 1e5 + 10;
int p[N];

struct Edge {
    int a, b, w;

    bool operator< (const Edge &t) const {
        return w < t.w;
    }
};

Edge edges[M];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    sort(edges, edges + m);
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res = max(res, w);
            cnt++;
        }
    }
    if (cnt < n - 1) puts("-1");
    else printf("%d\n", res);
    return 0;
}