//
// Created by cb on 2021/12/20.
//
#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* tmp;
    TreeNode* convertBiNode(TreeNode* root) {
        if(root == nullptr) return nullptr;
        convertBiNode(root->right);
        root->right = tmp;
        tmp = root;
        convertBiNode(root->left);
        root->left = nullptr;
        return tmp;
    }
};