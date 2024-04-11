#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // LIS
        int n = nums.size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                f[i] = f[i - 1] + 1;
            }
        }
        int ans1 = *max_element(f.begin(), f.end());
        // LDS
        vector<int> g(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                g[i] = g[i - 1] + 1;
            }
        }
        int ans2 = *max_element(g.begin(), g.end());
        return max(ans1, ans2);

        
    }
};