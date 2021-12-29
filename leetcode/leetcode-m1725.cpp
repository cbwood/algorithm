//
// Created by cb on 2021/12/28.
//

#include "string"
#include "vector"
#include "cstring"
#include "algorithm"
#include "iostream"
#include "unordered_map"
#include "map"
#include "unordered_set"

using namespace std;

class TrieNode {
public:
    TrieNode *next[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) next[i] = nullptr;
        isWord = false;
    }

//    ~TrieNode() {
//        for (int i = 0; i < 26; i++) delete next[i];
//    }
};

class Trie {
public:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

//    ~Trie() {
//        delete root;
//    }

    void insert(string word) {
        TrieNode *cur = root;
        for (auto &x: word) {
            if (cur->next[x - 'a'] == nullptr)
                cur->next[x - 'a'] = new TrieNode();
            cur = cur->next[x - 'a'];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size() && cur; i++)
            cur = cur->next[word[i] - 'a'];
        return cur && cur->isWord;
    }

    bool startWith(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size() && cur; i++)
            cur = cur->next[word[i] - 'a'];
        return cur;
    }
};


class Solution {
public:
    vector<string> ans, finalAns;
    int maxlen;
    int maxarea;
    map<int, unordered_set<string>, greater<>> len2string;
    Trie p;
    vector<string> maxRectangle(vector<string> &words) {
        maxlen = 0;
        maxarea = 0;
        for (auto &x: words) {
            p.insert(x);
            len2string[int(x.size())].insert(x);
            maxlen = max(maxlen, int(x.size()));
        }
        for (auto &x: len2string) {
            ans.clear();
            vector<TrieNode *> tr(x.first, p.root);
            dfs(x.first, tr);
        }
        return finalAns;
    }

    vector<bool> check(int m) {
        int n = ans.size();
        bool flag = true;
        for (int i = 0; i < m; i++) {
            TrieNode* cur = p.root;
            for (int j = 0; j < n; j++){
                int t = ans[j][i]-'a';
                if(cur->next[t] == nullptr)
                    return vector<bool>{false, false};
                cur = cur->next[t];
            }
            if(!(cur->isWord)) flag = false;
        }
        return vector<bool>{true, flag};
    }

    void dfs(int len, vector<TrieNode *> &tr) {
        if (maxlen * len <= maxarea) return;
        if (ans.size() >= maxlen) return;
        for (auto &x: len2string[len]) {
            bool check1 = true;
            bool check2 = true;
            vector<TrieNode *> tt;
            for(int i = 0; i < x.size(); i++){
                if(tr[i]->next[x[i]-'a'] == nullptr){
                    check1 = false;
                }else{
                    tt.push_back(tr[i]->next[x[i]-'a']);
                    if(!tr[i]->next[x[i] - 'a']->isWord)
                        check2 = false;
                }
                if(!check1 && !check2)
                    break;
            }
            if (check1){
                ans.push_back(x);
                if (check2&&ans.size() * len > maxarea) {
                    maxarea = ans.size() * len;
                    finalAns = vector<string>(ans);
                }
                dfs(len, tt);
                ans.pop_back();
            }

//            vector<bool> tmp = check(len);
//            if (tmp[0]) {
//                if (tmp[1]&&ans.size() * len > maxarea) {
//                    maxarea = ans.size() * len;
//                    finalAns = vector<string>(ans);
//                }
//                dfs(len);
//            }
//
//            ans.pop_back();
        }
    }
};

//int main() {
//    Solution so;
//    vector<string> words{"lcauj", "mdlby", "myulp", "yvkqn", "usajk", "rpj", "bojvf", "ukmkb", "afqbhs", "j", "ebe", "yacov",
//                   "wsaep", "zdk", "wziqrdd", "pcjfn", "nlrehaq", "dasrc", "lruvq", "dvca"};
//    so.maxRectangle(words);
//}