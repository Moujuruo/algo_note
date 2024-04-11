#include <cstdio>
#include <utility>
using namespace std;

const int N = 1e6 + 10;

// ph是第k个插入的点在堆中的位置，hp是下标为k的点是第几个插入的
int h[N], hp[N], ph[N];
int size = 0, m = 0;

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[u]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u) {
    while (u / 2 && h[u / 2] > h[u]) {
        heap_swap(u / 2, u);
        u >>= 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n --) {
        int op, x;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            size ++; m ++;
            ph[m] = size, hp[size] = m;
            h[size] = x;
            up(size);
        }
        else if (op == 2) {
            printf("%d\n", h[1]);
        }
        else {
            h[1] = h[size];
            size--;
            down(1);
        }
    }
    return 0;
}