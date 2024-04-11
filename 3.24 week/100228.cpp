#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

/*
给你一个正整数 k 。最初，你有一个数组 nums = [1] 。

你可以对数组执行以下 任意 操作 任意 次数（可能为零）：

选择数组中的任何一个元素，然后将它的值 增加 1 。
复制数组中的任何一个元素，然后将它附加到数组的末尾。
返回使得最终数组元素之 和 大于或等于 k 所需的 最少 操作次数
*/

#include <iostream>

class Solution {
public:
    int minOperations(int k) {
        if (k == 0 || k == 1) return 0;
        int cnt = 0, ans = 0x3f3f3f3f;
        int t = 0;
        for (int i = 2; i <= k; i++) {
            cnt = 0;
            t = i - 1;
            if (k % i == 0) {
                cnt = t + (k / i) - 1;
            } else {
                cnt = t + (k / i);
            }
            // cnt = t + (k / i);
            cout << cnt << endl;
            ans = min(ans, cnt);
        }
        return ans;
        
    }
};

int main() {
    int k;
    std::cout << "Enter a positive integer: ";
    std::cin >> k;
    
    Solution solution;
    int result = solution.minOperations(k);
    
    std::cout << "Minimum operations required: " << result << std::endl;
    
    return 0;
}
