#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

/*
你需要在一个集合里动态记录 ID 的出现频率。给你两个长度都为 n 的整数数组 nums 和 freq ，nums 中每一个元素表示一个 ID ，对应的 freq 中的元素表示这个 ID 在集合中此次操作后需要增加或者减少的数目。

增加 ID 的数目：如果 freq[i] 是正数，那么 freq[i] 个 ID 为 nums[i] 的元素在第 i 步操作后会添加到集合中。
减少 ID 的数目：如果 freq[i] 是负数，那么 -freq[i] 个 ID 为 nums[i] 的元素在第 i 步操作后会从集合中删除。
请你返回一个长度为 n 的数组 ans ，其中 ans[i] 表示第 i 步操作后出现频率最高的 ID 数目 ，如果在某次操作后集合为空，那么 ans[i] 为 0 。
输入：nums = [2,3,2,1], freq = [3,2,-3,1]

输出：[3,3,2,2]

解释：

第 0 步操作后，有 3 个 ID 为 2 的元素，所以 ans[0] = 3 。
第 1 步操作后，有 3 个 ID 为 2 的元素和 2 个 ID 为 3 的元素，所以 ans[1] = 3 。
第 2 步操作后，有 2 个 ID 为 3 的元素，所以 ans[2] = 2 。
第 3 步操作后，有 2 个 ID 为 3 的元素和 1 个 ID 为 1 的元素，所以 ans[3] = 2 。
*/

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> id_freq;
        unordered_map<long long, long long> freq_count;
        unordered_map<long long, long long> erased_freq;
        priority_queue<pair<long long, long long>> max_heap;
        vector<long long> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            long long prev_freq = id_freq[nums[i]];
            long long curr_freq = prev_freq + freq[i];
            
            if (curr_freq < 0) {
                curr_freq = 0;
            }
            
            id_freq[nums[i]] = curr_freq;

            if (erased_freq[prev_freq] > 0) {
                erased_freq[prev_freq]--;
            }
            
            if (prev_freq > 0) {
                freq_count[prev_freq]--;
                if (freq_count[prev_freq] == 0) {
                    freq_count.erase(prev_freq);
                    if (!max_heap.empty() && prev_freq == max_heap.top().first) {
                        max_heap.pop();
                    }
                    else {
                        erased_freq[prev_freq]++;
                    }
                }
            }

            while (!max_heap.empty() && erased_freq[max_heap.top().first] > 0) {
                erased_freq[max_heap.top().first]--;
                max_heap.pop();
            }
            
            freq_count[curr_freq]++;

            if (!max_heap.empty() && curr_freq == max_heap.top().first && freq_count[curr_freq] > max_heap.top().second) {
                max_heap.pop();
            }
            max_heap.push({curr_freq, freq_count[curr_freq]});
            
            ans.push_back(max_heap.empty() ? 0 : max_heap.top().first);
        }
        
        return ans;
    }
};

int main() {
    // [1,2,1,2,4,5,3,6,5]
// [3,3,-1,-2,3,5,1,4,-1]
    vector<int> nums = {1, 2, 1, 2, 4, 5, 3, 6, 5};
    vector<int> freq = {3, 3, -1, -2, 3, 5, 1, 4, -1};
    // vector<int> nums = {5, 3, 9, 4, 3, 9, 4};
    // vector<int> freq = {2, 4, 5, 2, -2, -4, 5};
    // vector<int> nums = {2, 3, 2, 1};
    // vector<int> freq = {3, 2, -3, 1};

    Solution solution;
    vector<long long> result = solution.mostFrequentIDs(nums, freq);

    cout << "Input nums: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Input freq: ";
    for (int f : freq) {
        cout << f << " ";
    }
    cout << endl;

    cout << "Output: ";
    for (long long res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}


// [5,3,9,4,3,9,4]
// [2,4,5,2,-2,-4,5]