/*
 *@File Name          :offer2-066.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/25 9:23
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
#include "map"

using namespace std;

class Node {
public:
    vector<Node *> nodes;
    int cnt;

    Node() {
        cnt = 0;
        nodes = vector<Node *>(26, nullptr);
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        node = new Node();
    }

    void insert(string key, int val) {
        auto tmp = node;
        int pre = ma[key];
        ma[key] = val;
        for (auto &s: key) {
            if (tmp->nodes[s - 'a'] == nullptr) {
                tmp->nodes[s - 'a'] = new Node();
            }
            tmp = tmp->nodes[s - 'a'];
            tmp->cnt += val - pre;
        }
    }

    int sum(string prefix) {
        auto tmp = node;
        int ans = 0;
        for (auto &s: prefix) {
            if (tmp->nodes[s - 'a'] == nullptr) {
                return 0;
            }
            tmp = tmp->nodes[s - 'a'];
        }
        ans = tmp->cnt;

        return ans;
    }

private:
    Node *node;
    map<string, int> ma;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */