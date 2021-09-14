//
// Created by cb on 2021/9/14.
//
#include "climits"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* root, long long l, long long r){
        if(root == nullptr) return true;
        if(root->val >= r || root->val <= l) return false;
        return dfs(root->left, l, root->val) && dfs(root->right, root->val, r);
    }
};