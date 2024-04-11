#include <cstdio>
using namespace std;

const int N = 1e5 + 1;
int n, k;
int H[N], W[N];

bool check(int x) {
    int tot = 0;
    for (int i = 0; i < n; i++)
        tot += (H[i] / x) * (W[i] / x);
    return tot >= k;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &H[i], &W[i]);
    }
    int l = 1, r = 100000;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%d", l);
    return 0;
}