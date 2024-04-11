#include <cstdio>
#include <cstring>
using namespace std;

const int N = 3e5 + 10;

int n1, n2, m;
bool st[N];
int match[N];
int h[N], e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a];
    h[a] = idx ++;
}

int find(int u) { // 匈牙利算法
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            if (!match[j] || find(match[j])) { // 如果 j 还没有匹配对象，或者 j 的匹配对象可以找到其他对象
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n1, &n2, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, 0, sizeof st);
        if (find(i)) res++; // 
    }
    printf("%d\n", res);
    return 0;
}