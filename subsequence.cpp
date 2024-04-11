#include <cstdio>
#include <vector>
using namespace std;

int n;
int a[1001];

vector<vector<int>> ans;
vector<int> path;

void dfs(int u) {
    ans.push_back(path);

    for (int i = u; i < n; i++) {
        path.push_back(a[i]);
        dfs(i + 1);
        path.pop_back();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    dfs(0);

    for (auto &x : ans) {
        for (auto &y : x)
            printf("%d ", y);
        puts("");
    }

    return 0;
}