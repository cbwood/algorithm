/*
 *@File Name          :offer2-065.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/25 8:55
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "string"
#include "set"
#include "map"

using namespace std;

//class Solution {
//public:
//    int minimumLengthEncoding(vector<string> &words) {
//        set<string> se(words.begin(), words.end());
//        int ans = 0;
//        for(auto &s: words){
//            for(int i = 1; i < s.size(); i++)
//                se.erase(s.substr(i));
//        }
//        for(auto &s: se)
//            ans += s.size()+1;
//        return ans;
//    }
//};

class Node {
public:
    vector<Node *> nodes;
    int cnt;

    Node() {
        nodes = vector<Node *>(26, nullptr);
        cnt = 0;
    }
};

class Solution {
public:
    Node *insert(const string &s) {
        auto tmp = node;
        for (auto &x: s) {
            if (tmp->nodes[x - 'a'] == nullptr) {
                tmp->nodes[x - 'a'] = new Node();
                tmp->cnt += 1;
            }
            tmp = tmp->nodes[x - 'a'];
        }
        return tmp;
    }

    int minimumLengthEncoding(vector<string> &words) {
        node = new Node();
        map<Node *, int> ma;
        int k = 0;
        for (auto &word: words) {
            std::reverse(word.begin(), word.end());
            ma[insert(word)] = k++;
        }
        int ans = 0;
        for (auto &x: ma) {
            if (x.first->cnt == 0)
                ans += words[x.second].size() + 1;
        }
        return ans;
    }

private:
    Node *node;
};