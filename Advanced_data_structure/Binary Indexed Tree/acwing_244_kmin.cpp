#include <cstdio>
using namespace std;

const int N = 100010;

int a[N], tr[N];
int n, ans[N];

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

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        tr[i] += 1;
        int j = i + lowbit(i);
        if (j <= n) tr[j] += tr[i];
    }
    for (int i = n; i; i--) {
        int k = a[i] + 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (sum(mid) >= k) r = mid;
            else l = mid + 1;
        }
        ans[i] = l;
        add(l, -1);
    }
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}