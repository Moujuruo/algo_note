#include <queue>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<string, int> dist;
unordered_map<string, pair<char, string>> pre;
char state[2][4];

void set(string &s) {
    for (int i = 0; i < 4; i++) state[0][i] = s[i];
    for (int i = 7, j = 0; j < 4; i--, j++) state[1][j] = s[i];
}

string get() {
    string res;
    for (int i = 0; i < 4; i++) res += state[0][i];
    for (int i = 3; i >= 0; i--) res += state[1][i];
    return res;
}

string move_0(string s) {
    set(s);
    for (int i = 0; i < 4; i++)
        swap(state[0][i], state[1][i]);
    return get();
}

string move_1(string s) {
    set(s);
    // 把最右边的一列移到最左边
    int v0 = state[0][3], v1 = state[1][3];
    for (int i = 3; i > 0; i--) {
        state[0][i] = state[0][i - 1];
        state[1][i] = state[1][i - 1];
    }
    state[0][0] = v0;
    state[1][0] = v1;
    return get();
}

string move_2(string s) {
    // 中间四格顺时针旋转
    set(s);
    int v = state[0][1];
    state[0][1] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[0][2];
    state[0][2] = v;
    return get();
} 


int bfs(string st, string ed) {
    if (st == ed) return 0;
    queue<string> q;
    q.push(st);
    dist[st] = 0;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        string m[3];
        m[0] = move_0(t);
        m[1] = move_1(t);
        m[2] = move_2(t);
        // printf("%s %s %s\n", m[0].c_str(), m[1].c_str(), m[2].c_str());

        for (int i = 0; i < 3; i++) {
            if (!dist.count(m[i])) {
                dist[m[i]] = dist[t] + 1;
                pre[m[i]] = {i + 'A', t};
                q.push(m[i]);
            }
            if (m[i] == ed) {
                return dist[m[i]];
            }
        }
    }
    return -1;
}


int main() {
    string st, ed;
    int x;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &x);
        ed += x + '0';
    }
    for (int i = 1; i <= 8; i++) 
        st += i + '0';
    bfs(st, ed);
    printf("%d\n", dist[ed]);

    string res;
    while (st != ed) {
        res += pre[ed].first;
        ed = pre[ed].second;
    }

    for (int i = res.size() - 1; i >= 0; i--) {
        printf("%c", res[i]);
    }
    return 0;
    
}

