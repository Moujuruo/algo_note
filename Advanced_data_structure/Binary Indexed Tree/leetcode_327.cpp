#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 100010;

int n, a[N], tr[N], s[N];
int lower, upper;
vector<int> alls;

int lowbit(int x) {
    return x & -x;
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += tr[i];
    return ans;
}

void add(int x, int val) {
    for (int i = x; i <= alls.size(); i += lowbit(i))
        tr[i] += val;
}

int findx(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}

int main() {
    int tot = 0;
    scanf("%d%d%d", &n, &lower, &upper);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
        if (s[i] >= lower && s[i] <= upper)
            tot ++;
        alls.push_back(s[i]);
        alls.push_back(s[i] - upper);
        alls.push_back(s[i] - lower);
    }
    // alls.push_back()
    // for (int i = 0; i <= n; i++)
    //     printf("%d ", s[i]);
    // printf("\n");
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (int i = 1; i <= n; i++) {
        int j = s[i];
        // if (j >= lower && j <= upper)
        int l = findx(j - upper) - 1, r = findx(j - lower);
        printf("%d %d %d %d\n", j, l + 1, r, findx(j));
        tot += sum(r) - sum(l);
        printf("sumr: %d suml: %d\n", sum(r), sum(l));
        add(findx(j), 1);
    }
    printf("%d", tot);
    return 0;
}
