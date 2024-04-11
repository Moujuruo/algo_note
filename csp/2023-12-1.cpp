#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int a[1010][11];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        flag = true;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (a[i][k] >= a[j][k])
                    break;
                if (k == m)
                    flag = false;
            }
            if (!flag) {
                printf("%d\n", j);
                break;
            }
        }
        if (flag) {
            printf("0\n");
        }
    }

    return 0;
}