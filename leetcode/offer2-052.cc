/*
 *@File Name          :offer2-052.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/13 9:05
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
    TreeNode *tmp = nullptr;

    TreeNode *increasingBST(TreeNode *root) {
        if (root == nullptr)
            return nullptr;
        TreeNode *r = increasingBST(root->right);
        root->right = tmp;
        tmp = root;
        TreeNode *l = increasingBST(root->left);
        root->left = nullptr;
        return tmp;
    }
};