#include <cstdio>
using namespace std;

const int N = 10;
int n;
bool used[N];
int ans[N];

void dfs(int x) {
    if (x == n) {
        for (int i = 0; i < n; i++)
            printf("%5d", ans[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            ans[x] = i;
            dfs(x + 1);
            used[i] = false;

        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}
