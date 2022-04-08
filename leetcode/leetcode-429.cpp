/*
 *@File Name          :leetcode-429.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/8 8:29
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
    vector<vector<int>> ans;

    void dfs(Node *cur, int dept) {
        if (cur == nullptr) return;
        if (ans.size() <= dept)
            ans.emplace_back();
        ans[dept].emplace_back(cur->val);
        for (auto &x: cur->children) {
            dfs(x, dept + 1);
        }
    }

    vector<vector<int>> levelOrder(Node *root) {
        dfs(root, 0);
        return ans;
    }
};