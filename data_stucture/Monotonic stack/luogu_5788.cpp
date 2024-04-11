#include <cstdio>
#include <utility>
using namespace std;

const int N = 3e6 + 10;

int n;
int top;
pair<int, int> stack[N];
int a[N], ans[N];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i >= 1; i--) {
        while (top && stack[top].second <= a[i]) top--;
        if (top) ans[i] = stack[top].first;
        else ans[i] = 0;
        stack[++top] = {i, a[i]};
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
