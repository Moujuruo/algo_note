#include <cmath>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

const int N = 5e5 + 10, INF = 2147483647;
typedef pair<int, int> PII;
int w[N], h[N], e[N], ne[N], idx;
int dist[N];
bool st[N];
int n, m, s;


void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void spfa(int s) {
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    st[s] = 1; // st 表示当前点是否在队列当中
    while (!q.empty()) {
       auto t = q.front();
       q.pop();
       st[t] = false;
       for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
       }
    }
    
}

int main() {
    printf("%lf", log2(16));
    scanf("%d%d%d", &n, &m, &s);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);       
    }
    spfa(s);
    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i] == 0x3f3f3f3f ? INF : dist[i]);
    return 0;
}