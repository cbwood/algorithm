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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == nullptr) return nullptr;
        TreeNode *cur = nullptr;
        if(root == p) cur = p;
        if(root == q) cur = q;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if(cur && (l || r))
            return cur;
        if(l && r)
            return root;
        if(l) return l;
        if(r) return r;
        return cur;
    }
};