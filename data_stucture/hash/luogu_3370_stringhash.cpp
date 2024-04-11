#include <cstdio>
#include <cstring>
using namespace std;

typedef unsigned long long ull ;
const int N = 3e5 + 10, null = 0x3f3f3f3f;
const ull P = 131;

char str[N];
ull h[N + 1];
int n;

ull GetValue(char s[]) {
    int len = strlen(s + 1);
    ull res = 0;
    for (int i = 1; i <= len; i++) {
        res = res * P + (ull)s[i];
    }
    // printf("%llu", res);
    return res;
}

int find(ull x) {
    int t = x % N;
    // printf("%d", t);
    while (h[t] != null && h[t] != x) {
        t ++;
        if (t == N) t = 0;
    }
    return t;
}

int main() {
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < N; ++i) {
        h[i] = 0x3F3F3F3F;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        ull k = GetValue(str);
        // printf("%llu", k);
        int x = find(k);
        if (h[x] == null) {
            ans++;
            h[x] = k;
        }
    }
    printf("%d", ans);
    return 0;
}