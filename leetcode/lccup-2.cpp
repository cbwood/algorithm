/*
 *@File Name          :lccup-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/16 14:53
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    set<int> se;

    void dfs(TreeNode *cur) {
        if (cur == nullptr) return;
        se.insert(cur->val);
        dfs(cur->left);
        dfs(cur->right);
    }

    int getNumber(TreeNode *root, vector<vector<int>> &ops) {
        int n = ops.size();
        ans = 0;
        dfs(root);
        for (int i = n - 1; i >= 0; --i) {
            auto l = se.lower_bound(ops[i][1]);
            auto r = l;
            if (*r <= ops[i][2]) {
                auto k = r;
                for (k = r; k != se.end(); k++) {
                    if (*k >= ops[i][1] && *k <= ops[i][2])
                        ans += ops[i][0];
                    else break;
                }
                k--;
                se.erase(l, k);

            }
            if (se.empty()) break;
        }
        return ans;
    }
};