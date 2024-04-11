#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;

const int N = 1e7 + 10;
int n, m, root;
int fa[N][20], depth[N];
int e[N], ne[N], h[N], idx;
int q[N], hh = 0, tt = -1;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a];
    h[a] = idx++;
}

void bfs(int root) {
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    q[++tt] = root;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (depth[j] > depth[t] + 1) {
                depth[j] = depth[t] + 1; // depth 表示节点的深度
                fa[j][0] = t; // fa[i][j] 表示从 i 开始，往上走 2^j 步所能到达的节点
                q[++tt] = j;
                for (int k = 1; k <= 19; k++)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    } 
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 19; k >= 0; k--)
        if (depth[fa[a][k]] >= depth[b]) a = fa[a][k]; // depth[fa[a][k]] 表示 a 往上走 2^k 步所能到达的节点的深度
    if (a == b) return a;
    for (int k = 19; k >= 0; k--) { 
        if (fa[a][k] != fa[b][k]) {
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n, &m, &root);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    bfs(root);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}