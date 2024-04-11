#include <cstdio>
using namespace std;

const int N = 2e5 + 10;
int used[N];
int n, m;
int l[N], r[N], e[N], idx;

void init() {
    l[1] = 0, r[0] = 1;
    r[1] = -1;
    idx = 2;
}

void insert(int k, int x) {
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}

void remove(int k) {
    if (used[k - 1]) {
        r[l[k]] = r[k];
        l[r[k]] = l[k];
        used[k - 1] = 0;
    }
}

int main() {
    scanf("%d", &n);
    init();
    insert(0, 1);
    used[1] = 1;
    for (int i = 2; i <= n; i++) {
        int k, p;
        scanf("%d%d", &k, &p);
        if (p == 0) {  // 将 i 插入到 k 号同学的左边
            insert(l[k + 1], i);
        }
        else {
            insert(k + 1, i);
        }
        used[i] = 1;
    }
    scanf("%d", &m);
    while (m--) {
        int x;
        scanf("%d", &x);
        remove(x + 1);
    }
    for (int i = r[0]; r[i] != -1; i = r[i])
        printf("%d ", e[i]);
    return 0;
}