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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr) return nullptr;
        if(root == p){
            check = true;
            if(root->right == nullptr)
                return nullptr;
            return inorderSuccessor(root->right, p);
        }
        auto *l = inorderSuccessor(root->left, p);
        if(l != nullptr) return l;
        if(check) return root;
        auto *r = inorderSuccessor(root->right, p);
        if(r != nullptr) return r;
        if(check) return root;
        return nullptr;
    }

private:
    bool check = false;
};