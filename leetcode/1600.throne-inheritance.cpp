/*
 * @lc app=leetcode.cn id=1600 lang=cpp
 * @lcpr version=30121
 *
 * [1600] 王位继承顺序
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
class ThroneInheritance {
public:
    string king;
    unordered_map<string, vector<string>> children;
    unordered_set<string> dead;

    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {  
        children[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        function<void(const string &)> dfs = [&](const string &name) {
            if (!dead.count(name)) {
                res.push_back(name);
            }
            for (auto &child: children[name]) {
                dfs(child);
            }
        };
        dfs(king);
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
// @lc code=end



/*
// @lcpr case=start
// ["ThroneInheritance", "birth", "birth", "birth", "birth", "birth", "birth", "getInheritanceOrder", "death","getInheritanceOrder"][["king"], ["king", "andy"], ["king", "bob"], ["king", "catherine"], ["andy", "matthew"], ["bob", "alex"], ["bob","asha"], [null], ["bob"], [null]]\n
// @lcpr case=end

 */

