#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

using PII = pair<int, int>;

const int N = 1010;
int n;
int Map[N][N];
bool st[N][N];

void bfs(int x, int y, bool &has_higher, bool &has_lower) {
    queue<PII> q;
    st[x][y] = true;
    q.push({x, y});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int tx = t.first, ty = t.second;
        for (int dx = tx - 1; dx <= tx + 1; dx ++) {
            for (int dy = ty - 1; dy <= ty + 1; dy ++) {
                if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
                if (dx == tx && dy == ty) continue;
                if (Map[dx][dy] != Map[tx][ty]) {
                    if (Map[dx][dy] > Map[tx][ty]) {
                        has_higher = true;
                        // cout << "1:" << dx << " " << dy << " " << tx << " " << ty << endl;
                        // cout << "2:" << Map[dx][dy] << " " << Map[tx][ty] << endl;
                    }
                    else has_lower = true;
                }
                else if (!st[dx][dy]) {
                    st[dx][dy] = true;
                    q.push({dx, dy});
                }
            }
        }

    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Map[i][j]);
        }
    }
    int peak = 0, valley = 0;
    bool has_higher = false, has_lower = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!st[i][j]) {
                has_higher = false;
                has_lower = false;
                // cout << "begin" << i << " " << j << endl;
                bfs(i, j, has_higher, has_lower);
                // cout << "=====" << i << " " << j << " " << has_higher << " " << has_lower << endl;
                if (!has_higher) peak ++;
                if (!has_lower) valley ++;
            }
        }
    }
    printf("%d %d", peak, valley);
    return 0;
}
