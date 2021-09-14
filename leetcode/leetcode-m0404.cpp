//
// Created by cb on 2021/9/14.
//
#include "cmath"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return check;
    }

    int dfs(TreeNode *root){
        if(root == nullptr) return 0;
        if(!check) return 1;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(abs(l-r) > 1) check = false;
        return max(l,r)+1;
    }

private:
    bool check = true;
};