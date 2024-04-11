#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    // 曼哈顿距离
    int distance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        int ans = INT_MAX;
        // 请你恰好移除一个点，返回移除后任意两点之间的 最大 距离可能的 最小 值

        // 枚举移除的点
        for (int i = 0; i < n; i++) {
           // 要计算剩下点的最大距离
            int max_dis = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = j + 1; k < n; k++) {
                    if (i == k || j == k) continue;
                    max_dis = max(max_dis, distance(points[j][0], points[j][1], points[k][0], points[k][1]));
                }
            }
            ans = min(ans, max_dis);
        }

        return ans;
    }
};