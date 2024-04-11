#include <cstdio>
using namespace std;

long double n;

int main() {
    scanf("%Lf", &n);
    long double l = 1, r = n;
    while (r - l > 1e-9) {
        long double mid = (l + r) / 2;
        // cout << mid << endl;
        if (mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%lld\n", (long long)(l + 0.1));
    // printf("%lf", l);
}