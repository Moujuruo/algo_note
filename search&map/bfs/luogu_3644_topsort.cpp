#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e3 + 10, M = 1e6 + 10;

int h[N], ne[N], e[N], idx;
int n;
int q[N], hh, tt = -1;
int d[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void topsort() {
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j] --;
            if (!d[j]) {
                q[++tt] = j;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        int x;
        while (1) {
            scanf("%d", &x);
            if (x == 0) break;
            d[x] ++;
            add(i, x);
        } 
    }
    topsort();
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}
