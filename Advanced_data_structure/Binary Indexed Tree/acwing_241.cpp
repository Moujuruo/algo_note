#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 200010;
int n;
int a[N], s[N];
int Greater[N], Lower[N];

int lowbit(int x) {
    return x & (-x);
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += s[i];
    return ans;
}

void add(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i))
        s[i] += val;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        Greater[a[i]] = sum(n) - sum(a[i]);
        Lower[a[i]] = sum(a[i] - 1);
        add(a[i], 1);
        printf("%d %d\n", sum(n), sum(a[i]));
    }

    memset(s, 0, sizeof(s));
    ll res1 = 0, res2 = 0;
    for (int i = n; i >= 1; i--) {
        res1 += (ll)Greater[a[i]] * (ll)(sum(n) - sum(a[i]));
        // printf("%d %d %d\n", a[i], Greater[a[i]], sum(n) - sum(a[i]));

        res2 += (ll)Lower[a[i]] * (ll)sum(a[i] - 1);
        add(a[i], 1);
    }
    printf("%lld %lld", res1, res2);
    return 0;
}