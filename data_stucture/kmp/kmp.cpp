#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6 + 10;
int ne[N];
char s[N], p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> (s + 1) >> (p + 1);
    int n = strlen(s + 1), m = strlen(p + 1);
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == m) {
            cout << i - m + 1 << endl;
            j = ne[j];
        }
    }

    // 输出 ne 数组
    for (int i = 1; i <= m; i++) cout << ne[i] << " ";
    return 0;
}