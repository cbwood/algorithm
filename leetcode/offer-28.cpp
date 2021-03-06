#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool dfs(TreeNode *l, TreeNode *r){
        if(l==NULL && r==NULL) return true;
        if(!l || !r) return false;
        if(l->val != r->val) return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root->left, root->right);
    }
};