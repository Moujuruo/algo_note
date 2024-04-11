#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
int n, k;
int p[N], d[N];

int find(int x) {
    if (x != p[x]) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    int ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (k--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        int px = find(x), py = find(y);
        if (x > n || y > n) ans ++;
        else if (op == 1) {
            if (px == py && (d[x] - d[y]) % 3 != 0)
                ans ++;
            else if (px != py) {
                p[px] = py;
                d[px] = d[y] - d[x]; 
            }
        }
        else {
            if (px == py && (d[x] - d[y] - 1) % 3) ans ++;
            else if (px != py) {
                p[px] = py;
                d[px] = d[y] - d[x] + 1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
