/*
 * @lc app=leetcode.cn id=705 lang=cpp
 * @lcpr version=30122
 *
 * [705] 设计哈希集合
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MyHashSet {
public:
    static const int N = 1e6 + 10;
    int h[N];
    MyHashSet() {
        memset(h, 0, sizeof h);
    }
    
    void add(int key) {
        h[key] = 1;
    }
    
    void remove(int key) {
        h[key] = 0;

    }
    
    bool contains(int key) {
        return h[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"][[], [1], [2], [1], [3], [2], [2], [2], [2]]\n
// @lcpr case=end

 */

