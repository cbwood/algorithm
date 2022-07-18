/*
 *@File Name          :leetcode-226.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/18 10:03
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
using namespace std;

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
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    swap(root->left, root->right);
    invertTree(root->right);
    invertTree(root->left);
    return root;
  }
};