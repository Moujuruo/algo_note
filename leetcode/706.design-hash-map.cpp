/*
 * @lc app=leetcode.cn id=706 lang=cpp
 * @lcpr version=30122
 *
 * [706] 设计哈希映射
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
class MyHashMap {
public:
    int h[1000005];

    MyHashMap() {
        memset(h, -1, sizeof h);

    }
    
    void put(int key, int value) {
        h[key] = value;

    }
    
    int get(int key) {
        return h[key];

    }
    
    void remove(int key) {
        h[key] = -1;

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"][[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]\n
// @lcpr case=end

 */

