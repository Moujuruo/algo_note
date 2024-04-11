// 给你一个字符串 s ，请找出满足每个字符最多出现两次的最长子字符串，并返回该子字符串的 最大 长度
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0 , r = 0, cnt = 0;
        unordered_map<char, int> m;
        int ans = 0;
        while (r < n) {
            m[s[r]] ++;
            if (m[s[r]] == 3) {
                cnt ++;
            }
            while (cnt > 0) {
                m[s[l]] --;
                if (m[s[l]] == 2) {
                    cnt --;
                }
                l ++;
            }
            ans = max(ans, r - l + 1);
            r ++;
        }
        return ans;

    }
};