/*
 *@File Name          :offer2-047.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/11 8:31
 *@Description        :
 *@Function List      :
 *@History            :
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *pruneTree(TreeNode *root) {
        if (root == nullptr)
            return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            root = nullptr;
        }
        return root;
    }
};