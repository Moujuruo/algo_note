// 区间修改，单点查询
#include <cstdio>
using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];
int tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += val;
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += tr[i];
    return ans;
}

// 大体思路是，对于每个数，维护一个差分数组，然后对于每个区间，将区间的两个端点的差分数组进行修改
// 树状数组用于维护差分数组
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    // for (int i = 1; i <= n; i++)
    //     add(i, a[i] - a[i - 1]);
    for (int i = 1; i <= n; i++) {
        tr[i] += a[i] - a[i - 1];
        int j = i + lowbit(i);
        if (j <= n) tr[j] += tr[i];
    }
    while (m--) {
        char Op[2];
        int l, r, d;
        scanf("%s%d", Op, &l);
        if (*Op == 'Q') {
            printf("%d\n", sum(l));
        }
        else {
            scanf("%d%d", &r, &d);
            add(l, d);
            add(r + 1, -d);
        }
    }
    return 0;
}