#include <algorithm>
#include <cstdio>

const int N = 1010;
int n;
int a[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            a[i][j] += std::max(a[i - 1][j], a[i - 1][j - 1]);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = std::max(res, a[n][i]);
    printf("%d", res);
    return 0;
}