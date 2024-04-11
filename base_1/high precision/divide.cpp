#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> Div(vector<int> &a, int b, ll &r) {
    vector<int> c;
    r = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main() {
    string A;
    int b;
    vector<int> a;
    cin >> A >> b;
    for (int i = A.size() - 1; i >= 0; i--) a.push_back(A[i] - '0');

    ll r = 0;
    auto C = Div(a, b, r);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    // cout << endl << r << endl;
    return 0;
}