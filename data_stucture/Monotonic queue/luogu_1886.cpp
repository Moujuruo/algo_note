#include <cstdio>
using namespace std;

const int N = 1e6 + 10;

int n, m;
int a[N];
int h1, t1;
int q1[N];

int main() {
    scanf("%d%d", &n, &m);
    h1  = 0, t1 = -1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        if (h1 <= t1 && i - m + 1 > q1[h1]) h1++;
        while (h1 <= t1 && a[q1[t1]] >= a[i]) t1--;
        q1[++t1] = i;
        if (i >= m - 1)
            printf("%d ", a[q1[h1]]); 
    }
    puts("");
    h1 = 0, t1 = -1;
    for (int i = 0; i < n; i++) {
        if (h1 <= t1 && i - m + 1 > q1[h1]) h1++;
        while (h1 <= t1 && a[q1[t1]] <= a[i]) t1--;
        q1[++t1] = i;
        if (i >= m - 1)
            printf("%d ", a[q1[h1]]); 
    }
    return 0;
}