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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr) return false;
        if(t2 == nullptr) return true;
        return dfs(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }

    bool dfs(TreeNode* t1, TreeNode* t2){
        if(t1 == t2) return true;
        if(t1 == nullptr || t2 == nullptr) return false;
        return t1->val == t2->val && dfs(t1->left, t2->left) && dfs(t1->right, t2->right);
    }
};