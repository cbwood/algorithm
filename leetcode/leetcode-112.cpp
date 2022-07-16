/*
 *@File Name          :leetcode-112.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/16 9:22
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
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;

    if (root->left == nullptr && root->right == nullptr &&
        targetSum - root->val == 0)
      return true;

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
  }
};