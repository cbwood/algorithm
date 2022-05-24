/*
 *@File Name          :offer2-064.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/24 9:32
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "string"

using namespace std;

class Node {
public:
    vector<Node *> nodes;
    bool is_end;

    Node() {
        nodes = vector<Node *>(26, nullptr);
        is_end = false;
    }
};

class MagicDictionary {
public:
    Node *node;

    /** Initialize your data structure here. */
    MagicDictionary() {
        node = new Node();
    }

    void buildDict(vector<string> dictionary) {
        for (auto &s: dictionary) {
            auto tmp = node;
            for (auto &x: s) {
                if (tmp->nodes[x - 'a'] == nullptr)
                    tmp->nodes[x - 'a'] = new Node();
                tmp = tmp->nodes[x - 'a'];
            }
            tmp->is_end = true;
        }
    }

    bool search(Node *node, string searchWord) {
        auto tmp = node;
        for (auto &x: searchWord) {
            if (tmp->nodes[x - 'a'] == nullptr)
                return false;
            tmp = tmp->nodes[x - 'a'];
        }
        return tmp->is_end;
    }

    bool search(string searchWord) {
        auto tmp = node;
        int n = searchWord.size();
        for (int i = 0; i < n; i++) {
            char t = searchWord[i];
            if (tmp->nodes[searchWord[i] - 'a'] == nullptr) {
                for (int j = 0; j < 26; j++)
                    if (tmp->nodes[j]) {
                        searchWord[i] = j + 'a';
                        if (search(tmp, searchWord.substr(i, n - i)))
                            return true;
                    }
                return false;
            } else {
                for (int j = 0; j < 26; j++)
                    if (j != t - 'a' && tmp->nodes[j]) {
                        searchWord[i] = j + 'a';
                        if (search(tmp, searchWord.substr(i, n - i)))
                            return true;
                    }
            }
            searchWord[i] = t;
            tmp = tmp->nodes[searchWord[i] - 'a'];
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */