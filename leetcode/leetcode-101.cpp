/*
 *@File Name          :leetcode-101.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/7 9:12
 *@Description        :
 *@Function List      :
 *@History            :
 */

struct TreeNode {
  int       val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool dfs(TreeNode* l, TreeNode* r) {
    if (l == nullptr && r == nullptr) return true;
    if (l == nullptr || r == nullptr) return false;

    if (l->val != r->val) return false;
    return dfs(l->left, r->right) && dfs(l->right, r->left);
  }
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return dfs(root->left, root->right);
  }
};