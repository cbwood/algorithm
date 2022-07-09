/*
 *@File Name          :leetcode-113.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/9 9:46
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
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
  vector<vector<int>> ans;

  void dfs(vector<int>& t, TreeNode* root, int targetSum, int sumx) {
    if (root == nullptr) return;
    sumx += root->val;
    t.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      if (targetSum == sumx) { ans.push_back(t); }
      t.pop_back();

      return;
    }
    dfs(t, root->left, targetSum, sumx);
    dfs(t, root->right, targetSum, sumx);
    t.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> t;
    dfs(t, root, targetSum, 0);
    return ans;
  }
};