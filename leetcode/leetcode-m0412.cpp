//
// Created by cb on 2021/9/14.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        int ansx = 0;
        dfs(root, sum, 0, ansx);
        return ansx + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int dfs(TreeNode* root, int sum, int x, int &ansx){
        if(x + root->val == sum) ansx++;
        int a = 0, b = 0;
        if(root->left) a = dfs(root->left, sum, x+root->val, ansx);
        if(root->right) b = dfs(root->right, sum, x+root->val, ansx);
        return  a+b;
    }
};

