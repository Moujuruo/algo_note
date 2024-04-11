#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 3e6 + 10;
int n;
ll ans = 0;
vector<int> pointX, pointY;
int tr[N];

struct Node {
    int l;
    int r;
    int index;

    bool operator < (const Node& w) const {
        if (index != w.index) return index < w.index;
        else if (l != w.l) return l < w.l;
        else return r < w.r; 
    }
};

struct Tag {
    int x;
    int y;
    int flag;

    bool operator < (const Tag& w) const {
        if (y != w.y) return y < w.y;
        else return flag > w.flag;
    }
};

vector<Node> merge(vector<Node> &intervals) {
    vector<Node> res;
    int st = -2e9, ed = -2e9, index = -2e9;
    sort(intervals.begin(), intervals.end());
    for (auto &interval: intervals) {
        if (interval.index == index) {
            if (interval.l > ed) {
                if (st != -2e9) res.push_back({st, ed, index}), ans += ed - st + 1;
                st = interval.l, ed = interval.r;
            }
            else {
                ed = max(ed, interval.r);
            }
        }
        else {
            if (st != -2e9) res.push_back({st, ed, index}), ans += ed - st + 1;
            st = interval.l, ed = interval.r, index = interval.index;
        }
    }
    if (st != -2e9) res.push_back({st, ed, index}), ans += ed - st + 1;
    return res;
}

int findx(int x, int k) {
    int l = 0, r = k;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (pointX[mid] >= x) r = mid;
        else l = mid + 1; 
    }
    return l + 1;
}

int lowbit(int x) {
    return x & -x;
}

void add(int x, int val) {
    for (int i = x; i <= pointX.size(); i += lowbit(i))
        tr[i] += val;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main() {
    vector<Node> cols, rows;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 == x2) cols.push_back({min(y1, y2), max(y1, y2), x1});
        else rows.push_back({min(x1, x2), max(x1, x2), y1});
        pointX.push_back(x1), pointX.push_back(x2);
        pointY.push_back(y1), pointY.push_back(y2);
    }
    vector<Node> mergeCols, mergeRows;
    mergeCols = merge(cols);
    mergeRows = merge(rows);
    // printf("%d\n", ans);

    sort(pointY.begin(), pointY.end());
    pointY.erase(unique(pointY.begin(), pointY.end()), pointY.end());
    sort(pointX.begin(), pointX.end());
    pointX.erase(unique(pointX.begin(), pointX.end()), pointX.end());

    // for (int i = 0; i <pointX.size(); i++)
    //     printf("%d ", pointX[i]);
    // printf("\n");

    vector<Tag> tags;
    for (auto &col: mergeCols) {
        // printf("col =%d %d %d\n", col.index, col.l, col.r);
        tags.push_back({col.index, col.l, 1});
        tags.push_back({col.index, col.r, -1});
    }
    sort(tags.begin(), tags.end());
    int k = 0, t = 0;
    for (int i = 0; i < pointY.size(); i++) {
        while (k < tags.size() && pointY[i] == tags[k].y && tags[k].flag == 1) {
            int j = findx(tags[k].x, pointX.size());
            add(j, 1);
            // printf("j = %d, tag.x = %d\n", j, tags[k].x);
            k++;
        }
        while (t < mergeRows.size() && mergeRows[t].index == pointY[i]) {
            int l = findx(mergeRows[t].l, pointX.size()) - 1;
            int r = findx(mergeRows[t].r, pointX.size());
            // printf("l = %d r = %d\n", l, r);
            // printf("sum(r) = %d, sum (l) = %d\n", sum(r), sum(l));
            ans -= (sum(r) - sum(l));
            t++;
        }
        while (k < tags.size() && pointY[i] == tags[k].y && tags[k].flag == -1) {
            int j = findx(tags[k].x, pointX.size());
            add(j, -1);
            k++;
        }
    }
    printf("%lld", ans);
    return 0;
}
