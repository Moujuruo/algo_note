#include <cstdio>
#include <unordered_map>
using namespace std;

const int N = 1e6 + 10;

unordered_map<int, int> value_to_index;
int n;
int head, idx, e[N], ne[N];

void init() {
    head = -1;
    idx = 0;
}

void insert_after_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    value_to_index[x] = idx;
    idx++;
}

void insert_y_after_x(int x, int y) {
    int k = value_to_index.count(x);
    if (k) {
        int i = value_to_index[x];
        e[idx] = y;
        ne[idx] = ne[i];
        ne[i] = idx;
        value_to_index[y] = idx;
        idx++;
    }    
}

// void delete_after_x(int x) {
//     for (int i = head; i != -1; i = ne[i]) {
//         if (ne[i] != -1 && e[i] == x) {
//             ne[i] = ne[ne[i]];
//             return;
//         }
//     }
// }

void delete_after_x(int x) {
    int i = value_to_index[x];
    ne[i] = ne[ne[i]];
}

// int query_after_x(int x) {
//     for (int i = head; i != -1; i = ne[i]) {
//         if (e[i] == x) {
//             return e[ne[i]];
//         }
//     }
//     return 0;
// }

int query_after_x(int x) {
    if (value_to_index.count(x)) {
        int i = value_to_index[x];
        return e[ne[i]];
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    init();
    insert_after_head(1);
    while (n--) {
        int op, x, y;
        scanf("%d%d", &op, &x);
        if (op == 1) {
            scanf("%d", &y);
            insert_y_after_x(x, y);
        }
        else if (op == 2) {
            printf("%d\n", query_after_x(x));
        }
        else if (op == 3) {
            delete_after_x(x);
        }
    }
    return 0;
}