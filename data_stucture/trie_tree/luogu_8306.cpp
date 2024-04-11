#include <cstring>
#include <cstdio>
using namespace std;

const int N = 3e6 + 10;
const int M = 49;
char s[N];
int T, idx = 0;
int son[N][77], cnt[N];

void insert(char x[]) {
    int p = 0;
    int n = strlen(x);
    for (int i = 0; i < n; i++) {
        int u = x[i] - 'a' + M;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;
    }
}

int query(char x[]) {
    int p = 0;
    int n = strlen(x);
    for (int i = 0; i < n; i++) {
        int u = x[i] - 'a' + M;
        if (son[p][u]) p = son[p][u];
        else return 0;
    }
    return cnt[p];
}

int main() {
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i <= idx; i++) 
            for (int j = 0; j <= 76; j++)
                son[i][j] = 0;
        for (int i = 0; i <= idx; i++)
            cnt[i] = 0;
        idx = 0;
        int n, q;
        scanf("%d%d", &n, &q);
        while (n--) {
            scanf("%s", s);
            insert(s);
        }
        while (q--) {
            scanf("%s", s);
            printf("%d\n", query(s));
        }
    }
    return 0;
}