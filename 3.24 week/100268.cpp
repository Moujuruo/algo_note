


#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
private:
    struct TrieNode {
        vector<pair<int, int>> indices; // 存储字符串下标和长度
        TrieNode* children[26];
        
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    void insertWord(TrieNode* root, string& word, int index) {
        TrieNode* node = root;
        for (int i = word.length() - 1; i >= 0; i--) {
            int c = word[i] - 'a';
            if (node->children[c] == nullptr) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->indices.push_back({index, word.length()});
        }
    }
    
    int findLongestSuffix(TrieNode* root, string& query) {
        TrieNode* node = root;
        for (int i = query.length() - 1; i >= 0; i--) {
            int c = query[i] - 'a';
            if (node->children[c] == nullptr) {
                break;
            }
            node = node->children[c];
        }
        
        if (node->indices.empty()) {
            return -1;
        }
        
        int minLength = INT_MAX;
        int minIndex = -1;
        for (auto p : node->indices) {
            if (p.second < minLength || (p.second == minLength && p.first < minIndex)) {
                minLength = p.second;
                minIndex = p.first;
            }
        }
        
        return minIndex;
    }
    
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();

        int min_str = INT_MAX;
        int min_idx = -1;
        for (int i = 0; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].size() < min_str) {
                min_str = wordsContainer[i].size();
                min_idx = i;
            }
        }
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            insertWord(root, wordsContainer[i], i);
        }
        
        vector<int> ans;
        for (string query : wordsQuery) {
            int k = findLongestSuffix(root, query);
            if (k == -1) {
                ans.push_back(min_idx);
            } else {
                ans.push_back(k);
            }
            // ans.push_back(findLongestSuffix(root, query));
        }
        
        return ans;
    }
};

class Solution {
private:
    struct TrieNode {
        vector<pair<int, int>> indices;
        int children[26];
        
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = -1;
            }
        }
    };
    
    vector<TrieNode> trie;
    
    void insertWord(string& word, int index) {
        int node = 0;
        for (int i = word.length() - 1; i >= 0; i--) {
            int c = word[i] - 'a';
            if (trie[node].children[c] == -1) {
                trie[node].children[c] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].children[c];
            trie[node].indices.push_back({index, word.length()});
        }
    }
    
    int findLongestSuffix(string& query) {
        int node = 0;
        for (int i = query.length() - 1; i >= 0; i--) {
            int c = query[i] - 'a';
            if (trie[node].children[c] == -1) {
                break;
            }
            node = trie[node].children[c];
        }
        
        if (trie[node].indices.empty()) {
            return -1;
        }
        
        int minLength = INT_MAX;
        int minIndex = -1;
        for (auto p : trie[node].indices) {
            if (p.second < minLength || (p.second == minLength && p.first < minIndex)) {
                minLength = p.second;
                minIndex = p.first;
            }
        }
        
        return minIndex;
    }
    
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.emplace_back();

        int min_str = INT_MAX;
        int min_idx = -1;
        for (int i = 0; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].size() < min_str) {
                min_str = wordsContainer[i].size();
                min_idx = i;
            }
        }
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            insertWord(wordsContainer[i], i);
        }
        
        vector<int> ans;
        for (string query : wordsQuery) {
            // ans.push_back(findLongestSuffix(query));
            int k = findLongestSuffix(query);
            if (k == -1) {
                ans.push_back(min_idx);
            } else {
                ans.push_back(k);
            }
        }
        
        return ans;
    }
};
