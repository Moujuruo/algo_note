#include <cstdio>
#include <algorithm>

const int N = 15;
int w[N][N];
int f[2 * N][N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (;;) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        w[a][b] = c;
    }

    for (int k = 2; k <= n + n; k++) {
        for (int i1 = 1; i1 <= n && i1 < k; i1 ++) {
            for (int i2 = 1; i2 <= n && i2 < k; i2 ++) {
                int j1 = k - i1, j2 = k - i2;
                int &x = f[k][i1][i2];
                int t = w[i1][j1];
                if (i1 != i2) t += w[i2][j2];
                x = std::max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                x = std::max(x, f[k - 1][i1 - 1][i2] + t);
                x = std::max(x, f[k - 1][i1][i2 - 1] + t);
                x = std::max(x, f[k - 1][i1][i2] + t);
            }
        }
    }

    printf("%d", f[2 * n][n][n]);
    return 0;
}