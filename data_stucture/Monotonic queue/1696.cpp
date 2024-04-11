#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
    static const int N = 2e5 + 10;
    int q[N];
    int hh = 0, tt = -1;

public:
    int maxResult() {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int k;
        cin >> k;
        int ans = 0;
        vector<int> f(n + 1, 0);
        memset(q, 0, sizeof q);
        f[0] = nums[0];
        q[++tt] = 0;
        for (int i = 1; i < n; i++) {
            cout << q[hh] << endl;
            f[i] = f[q[hh]] + nums[i];
            if (hh <= tt && i - k + 1 > q[hh]) hh++;
            while (hh <= tt && nums[i] >= nums[q[tt]]) {
                tt--;
            }
            q[++tt] = i;
        }
        return f[n - 1];
    }
};

int main() {
    Solution sol;
    int res = sol.maxResult();
    cout << res << endl;
    return 0;
}