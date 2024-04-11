#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        // 对顶堆
        priority_queue<long long, vector<long long>, greater<long long>> small; // 小顶堆
        priority_queue<long long, vector<long long>, less<long long>> large; // 大顶堆
        int n = nums.size();
        // 建立对顶堆求中位数，先不管k
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // 第奇数个数
                large.push(nums[i]);
                small.push(large.top());
                large.pop();
            }
            else {
                small.push(nums[i]);
                large.push(small.top());
                small.pop();
            }
        }
        // cout << small.top() << " " << large.top() << endl;
        long long ans = 0;
        // 将 nums 中位数 变为 k 所需要的 最少 操作次数
        // 1. 如果中位数是k，不需要操作 2. 如果中位数不等于k，则将其变为k
        while (true) {
            long long mid = small.top();
            // cout << mid << endl;
            if (mid == k) break;
            ans += abs(mid - k);
            if (mid < k) {
                small.pop();
                small.push(k);
            }
            else {
                small.pop();
                large.push(k);
                small.push(large.top());
                large.pop();
            } 
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,5,6,8,5};
    int k = 4;
    cout << s.minOperationsToMakeMedianK(nums, k) << endl;
}
