#include <vector>
using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int pre = nums[0], cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == pre) {
                ans += cnt * (cnt + 1) / 2;
                cnt = 1;
            }
            else {
                cnt ++;
                pre = nums[i];
            }
        }
        return ans + cnt * (cnt + 1) / 2;
    }
};
