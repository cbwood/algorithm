/*
 *@File Name          :leetcode-589.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/10 8:58
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node *root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }

    void dfs(vector<int> &ans, Node *cur) {
        if (cur == nullptr) return;
        ans.emplace_back(cur->val);
        for (auto &x: cur->children) {
            dfs(ans, x);
        }
    }
};