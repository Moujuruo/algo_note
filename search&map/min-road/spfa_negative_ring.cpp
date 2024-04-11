#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e6 + 10; 
int h[N], ne[N], e[N], w[N], idx;
int dist[N], cnt[N];
int q[N], hh = 0, tt = -1;
bool st[N];
int n, m;


void add(int a, int b, int v) {
    e[idx] = b, w[idx] = v;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool spfa() {
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(q, 0, sizeof q);
    hh = 0, tt = -1;

    q[++tt] = 1;
    st[1] = true;
    dist[1] = 0;
    while (hh <= tt) {
        auto t = q[hh++];
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q[++tt] = j;
                    st[j] = true;
                    cnt[j] = cnt[t] + 1;
                    if (cnt[j] >= n) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        memset(h, -1, sizeof h);
        memset(e, 0, sizeof e);
        memset(ne, 0, sizeof ne);
        memset(w, 0, sizeof w);
        idx = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            if (w >= 0)
                add(v, u, w);
        }
        bool flag = spfa();
        if (flag) puts("YES");
        else puts("NO");
    }
}