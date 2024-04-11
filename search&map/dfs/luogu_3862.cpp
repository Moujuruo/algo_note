#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e3 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
bool vis[N];
int ans = 0;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++; 
}

void dfs(int u) {
    vis[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!vis[j]) {
            if (j > ans) ans = j;
            dfs(j);
        }
    } 
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    for (int i = 1; i <= n; i++) {
        ans = i;
        memset(vis, 0, sizeof vis);
        dfs(i);
        printf("%d ", ans);
    }
    return 0;
}