#include <cstdio>
#include <vector>
using namespace std;

using ll = long long;
// set<ll> s;
vector<ll> s;

bool is_prime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

ll fast_pow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        ll t = fast_pow(a, b / 2);
        return t * t;
    } else {
        return a * fast_pow(a, b - 1);
    }
}

int main() {
    int q;
    for (ll i = 1; i <= 100000; i++) {
        if (is_prime(i)) {
            s.push_back(i);
        }
    }
    scanf("%d", &q);
    while (q --) {
        ll n;
        int k;
        scanf("%lld%d", &n, &k);
        int cnt = 0;
        ll ans = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > n) break;
            while (n % s[i] == 0) {
                n /= s[i];
                cnt++;
                // printf("%lld ", s[i]);
            }
            if (cnt >= k) {
                // printf("%lld %d\n", s[i], cnt);
                ans *= fast_pow(s[i], cnt);
                // printf("ans = %lld\n", ans);
            }
            cnt = 0;
        }
        printf("%lld\n", ans);

    }
    return 0;

}

