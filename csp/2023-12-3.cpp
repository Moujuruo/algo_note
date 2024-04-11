#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

const int N = 2010;

using PII = pair<int, int>;

vector<PII> children[N];
int parent[N], w[N];
bool vis[N];
int n, m, tot;
int min_idx = 0, min_val = 1e9, min_w = 1e9;

int dfs(int u) { 
    if (vis[u]) return 0;
    int sum = w[u];
    for (auto &child: children[u]) {
        sum += dfs(child.first); // 递归计算子结点的总重量和
    }
    if (abs(2 * sum - tot) < min_val || (abs(2 * sum - tot) == min_val && u < min_idx)) { // x - (y - x) = 2x - y, 即为它和其全部后代类别的权重之和，其余全部类别的权重之和，二者差值的绝对值
        min_w = sum; 
        min_val = abs(2 * sum - tot); // 更新最小值和最小值对应的结点编号
        min_idx = u; // 更新最小值对应的结点编号为当前结点编号u
    }
    return sum; 
}

bool find(int u, int query) {
    if (query == u) return true; // 找到目标结点，返回true
    for (auto &child: children[u]) { // 递归查找子结点
        if (find(child.first, query)) return true; // 找到目标结点，返回true
    } // 否则返回false，表示未找到目标结点。
    return false; 
}

void new_tot(int u) {
    tot += w[u];
    for (auto &child: children[u]) { // 递归更新子结点的总重量和
        if (!vis[child.first]) { // 如果子结点未被访问过，则递归更新其总重量和。
            new_tot(child.first); // 递归更新子结点的总重量和。
        } // 否则，不更新，因为子结点已经被访问过，其总重量和已经计算过。
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int k = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        tot += w[i];
    }
    k = tot;
    // 初始化幽灵结点
    children[0].push_back({1, w[1]});
    parent[1] = 0; // 幽灵结点为根结点
    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        parent[i] = p;
        children[p].push_back({i, w[i]});
    }
    while (m --) {
        memset(vis, false, sizeof(vis));
        int query;
        scanf("%d", &query);
        min_val = 1e9; 
        min_idx = 0; 
        int root = 1;
        tot = k;
        while (1) {
            min_val = 1e9; 
            min_idx = 0; 
            dfs(root);
            printf("%d ", min_idx); // 输出结果
            if (query == min_idx && children[min_idx].empty()) break;
            if (query == min_idx || find(min_idx, query)) {
                root = min_idx;
                tot = 0;
                new_tot(root);
            }
            else {
                vis[min_idx] = true; 
                tot -= min_w; // 更新总重量
                // printf("%d \n", tot);
                if (tot == w[root]) break;
            }

        }
        puts(""); // 输出换行符

    }
    return 0;
}