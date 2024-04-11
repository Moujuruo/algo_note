#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5 + 1;
int T;
int x, y;
int dist[N];

int bfs() {
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    while (!q.empty()) {
        auto t = q.front();
        if (t == y) return dist[y];
        q.pop();
        if (t + 1 < N && dist[t + 1] == -1) {
            dist[t + 1] = dist[t] + 1;
            q.push(t + 1);
        }
        if (t - 1 >= 0 && dist[t - 1] == -1) {
            dist[t - 1] = dist[t] + 1;
            q.push(t - 1);
        }
        if (t * 2 < N && dist[2 * t] == -1) {
            dist[t * 2] = dist[t] + 1;
            q.push(t * 2);
        }
    }
    return -1;
}

int main() {
    scanf("%d", &T);
    while (T --) {
        memset(dist, -1, sizeof dist);
        scanf("%d%d", &x, &y);
        printf("%d\n", bfs());
    }
}