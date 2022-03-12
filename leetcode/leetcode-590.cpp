/*
 *@File Name          :leetcode-590.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/12 8:50
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
    vector<int> ans;

    void dfs(Node *cur) {
        if (cur == nullptr) return;
        for (auto &x: cur->children)
            dfs(x);
        ans.emplace_back(cur->val)
        l
    }

    vector<int> postorder(Node *root) {
        dfs(root);
        return ans;
    }
};