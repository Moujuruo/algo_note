#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 101;
int a[N], f[N], g[N];

int k;

int main() {
    scanf("%d", &k);
    while (k --) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        int res = 0;
        f[1] = g[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = g[i] = 1;
            for (int j = 1; j < i; j++) {
                if (a[i] < a[j]) f[i] = std::max(f[i], f[j] + 1);
                if (a[i] > a[j]) g[i] = std::max(g[i], g[j] + 1);
                res = std::max(res, f[i]);
                res = std::max(res, g[i]);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}