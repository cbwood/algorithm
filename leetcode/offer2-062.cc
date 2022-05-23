/*
 *@File Name          :offer2-062.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/23 9:19
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "string"

using namespace std;

class Node {
public:
    Node() {
        next_ = vector<Node *>(26, nullptr);
        is_end_ = false;
    }

public:
    vector<Node *> next_;
    bool is_end_;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        node = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto tmp = node;
        for (auto &x: word) {
            if (tmp->next_[x - 'a'] == nullptr) {
                tmp->next_[x - 'a'] = new Node();
            }
            tmp = tmp->next_[x - 'a'];
        }
        tmp->is_end_ = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto tmp = node;
        for (auto &x: word) {
            if (tmp->next_[x - 'a'] == nullptr) {
                return false;
            }
            tmp = tmp->next_[x - 'a'];
        }
        return tmp->is_end_;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto tmp = node;
        for (auto &x: prefix) {
            if (tmp->next_[x - 'a'] == nullptr) {
                return false;
            }
            tmp = tmp->next_[x - 'a'];
        }
        return true;
    }

private:
    Node *node;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */