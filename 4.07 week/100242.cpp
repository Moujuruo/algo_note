#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int distance(char a, char b) {
        return min(abs(a - b), 26 - abs(a - b));
    }

    string getSmallestString(string s, int k) {
        // 贪心，从前往后，能放最小的就放最小的
        string ans = s;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') continue;
            int dis = distance(s[i], 'a');
            if (k >= dis) {
                ans[i] = 'a';
                k -= dis;
            }
            else { // 尽量字典序小
                int tmp1 = (s[i] - 'a' + k) % 26;
                int tmp2 = (s[i] - 'a' - k + 26) % 26;
                ans[i] = min(tmp1, tmp2) + 'a';
                break;
            }
        }
        return ans;
    }
};