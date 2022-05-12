/*
 *@File Name          :offer2-049.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/12 8:53
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

    void dfs(TreeNode *root, int &ans, int cur) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            ans += cur * 10 + root->val;
            return;
        }
        dfs(root->left, ans, cur * 10 + root->val);
        dfs(root->right, ans, cur * 10 + root->val);
    }

    int sumNumbers(TreeNode *root) {
        int ans = 0;
        dfs(root, ans, 0);
        return ans;
    }
};