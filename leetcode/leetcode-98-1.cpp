/*
 *@File Name          :leetcode-98-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/12 10:06
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "climits"
#include "vector"

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
  bool isValidBST(TreeNode* cur, long long l, long long r) {
    if (cur == nullptr) return true;
    if (cur->val <= l || cur->val >= r) return false;
    return isValidBST(cur->left, l, cur->val) &&
           isValidBST(cur->right, cur->val, r);
  }

  bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
  }
};