// 数列离散化
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 300010;

int n, T;
int a[N];
vector<int> alls;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 从1开始编号
}

int main() {
    scanf("%d", &T);
    while (T--) {
        alls.clear();
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            alls.push_back(a[i]);
        }
        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());
        for (int i = 1; i <= n; i++) {
            printf("%d ", find(a[i]));
        }
        printf("\n");
    }
}

