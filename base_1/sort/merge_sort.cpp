#include <cstdio>
using namespace std;

const int N = 100001;

int a[N], tmp[N];
int n;

void merge_sort(int a[], int l, int r) {
    if (l >= r) return ;
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid), merge_sort(a, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int i = 0, j = l; i < k; i++, j++)
        a[j] = tmp[i]; 
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}