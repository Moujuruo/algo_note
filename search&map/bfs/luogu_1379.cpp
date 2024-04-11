#include <iostream>
#include <map>
#include <string>
using namespace std;

const int N = 500001;
string n;
map<string, int> Map;
string q[N];
int hh = 0, tt = 0;
const int dx[4] = {1, -1, 0, 0},
          dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n;
    Map[n] = 0;
    q[0] = n;
    while (hh <= tt) {
        auto t = q[hh++];
        // cout << t << endl;
        int step = Map[t];
        if (t == "123804765") {
            cout << step;
            break;
        }
        int index = t.find('0'), x = index / 3, y = index % 3;
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx > 2 || ty < 0 || ty > 2) continue;
            swap(t[index], t[tx * 3 + ty]);
            if (!Map.count(t)) {
                Map[t] = step + 1;
                q[++tt] = t;
            }
            swap(t[index], t[tx * 3 + ty]);
        }
    }
    return 0;
}