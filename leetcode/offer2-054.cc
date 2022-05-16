/*
 *@File Name          :offer2-054.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/16 9:04
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
    int ans = 0;

    void dfs(TreeNode *cur) {
        if (cur == nullptr)
            return;
        dfs(cur->right);
        cur->val += ans;
        ans = cur->val;
        dfs(cur->left);
    }

    TreeNode *convertBST(TreeNode *root) {
        dfs(root);
        return root;
    }
};