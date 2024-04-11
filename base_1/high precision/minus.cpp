#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Minus(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (a[i] - t < b[i]) {
            c.push_back((10 + a[i] - b[i]  - t) % 10);
            t = 1;
        }
        else {
            c.push_back(a[i] - b[i] - t);
            t = 0;
        }
    }
    return c;
}


int main() {
    vector<int> a, b;
    string A, B;
    bool flag = 0;
    cin >> A >> B;
    if (A.size() < B.size() || (A.size() == B.size() && (A[0] - '0') < (B[0] - '0'))) {
        swap(A, B);
        flag = 1;
    }
        
    // cout << A << " " << B << endl;
    
    for (int i = A.size() - 1; i >= 0; i--) a.push_back(A[i] - '0');
    for (int i = B.size() - 1; i >= 0; i--) b.push_back(B[i] - '0');
    int less = a.size() - b.size();
    for (int i = 0; i < less; i++) 
        b.push_back(0);


    vector<int> c = Minus(a, b);
    int t = 0;

    for (int i = c.size() - 1; i >= 0; i--)
        if (c[i] != 0) {
            t = i;
            break;
        }
            
    if (flag) printf("-");
    if (t == 0) printf("%d", c[0]);
    else {
        for (int i = t; i >= 0; i--) printf("%d", c[i]);
    }

    return 0;
}