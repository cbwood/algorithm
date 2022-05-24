/*
 *@File Name          :offer2-063.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/24 9:03
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Trie {
public:
    Trie() {
        node_ = vector<Trie *>(26, nullptr);
        is_end_ = false;
    }

    void insert(string word) {
        auto tmp = this;
        for (auto &x: word) {
            if (tmp->node_[x - 'a'] == nullptr)
                tmp->node_[x - 'a'] = new Trie();
            tmp = tmp->node_[x - 'a'];
        }
        tmp->is_end_ = true;
    }

    int find(string word) {
        auto tmp = this;
        int k = 0;
        for (auto &x: word) {
            if (tmp->is_end_)
                return k;
            if (tmp->node_[x - 'a'] == nullptr)
                return -1;
            k++;
            tmp = tmp->node_[x - 'a'];
        }
        return tmp->is_end_ ? k : -1;
    }

private:
    vector<Trie *> node_;
    bool is_end_;
};

class Solution {
public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        auto t = new Trie();
        for (auto &x: dictionary) {
            t->insert(x);
        }
        string ans;
        int prex = 0;
        int len = sentence.size();
        for (int i = 0; i < len; i++) {
            if (sentence[i] == ' ') {
                string tmp = sentence.substr(prex, i - prex);
                int k = t->find(tmp);
                if (k == -1) {
                    ans += tmp + " ";
                } else {
                    ans += tmp.substr(0, k) + " ";
                }
                prex = i + 1;
            }
        }
        if (prex != len) {
            string tmp = sentence.substr(prex, len - prex);
            int k = t->find(tmp);
            if (k == -1) {
                ans += tmp;
            } else {
                ans += tmp.substr(0, k);
            }
        }
        return ans;
    }
};