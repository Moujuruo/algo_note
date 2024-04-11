#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Mul(vector<int> &a, vector<int> &b) {
    vector<int> c(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i + j] += a[i] * b[j];
        }
    }

    int t = 0;
    for (int i = 0; i < c.size(); i++) {
        c[i] += t;
        t = c[i] / 10;
        c[i] %= 10;
    }
    if (t) c.push_back(t);
    while (c.size() > 1 && c.back() == 0) c.pop_back();

    return c;
}

int main() {
    string A, B;
    vector<int> a, b;
    cin >> A >> B;
    for (int i = A.size() - 1; i >= 0; i--) a.push_back(A[i] - '0');
    for (int i = B.size() - 1; i >= 0; i--) b.push_back(B[i] - '0');

    auto c = Mul(a, b);

    for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
    return 0;
}