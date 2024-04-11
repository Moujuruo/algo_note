class Solution {
public:
    static bool compareIntervals(const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int st = -1, end = -1;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compareIntervals);
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] > end) {
                if (st != -1) ans.push_back({st, end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
            else {
                end = max(end, intervals[i][1]);
            }
        }
        if (st != -1) ans.push_back({st, end});
        return ans;
    }
};