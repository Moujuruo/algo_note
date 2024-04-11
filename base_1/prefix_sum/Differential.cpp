#include <cstdio>
using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        insert(i, i, x); // 差分数组的插入操作
    }

    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c); // 区间[l, r]加c
        b[l] += c;
        b[r + 1] -= c;
    }

    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);
    return 0;
}