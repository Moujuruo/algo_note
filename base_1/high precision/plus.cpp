#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Add(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (t) c.push_back(1);
    return c;
}


int main() {
    vector<int> a, b;
    string A, B;
    cin >> A >> B;
    for (int i = A.size() - 1; i >= 0; i--) a.push_back(A[i] - '0');
    for (int i = B.size() - 1; i >= 0; i--) b.push_back(B[i] - '0');

    vector<int> c = Add(a, b);

    for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
    return 0;
}