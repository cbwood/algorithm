/*
 *@File Name          :leetcode-662.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/29 9:17
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "climits"
#include "deque"
#include "map"
#include "queue"
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
  vector<pair<unsigned long long, unsigned long long>> dp;
  unsigned long long                                   ans;

  void dfs(TreeNode* root, unsigned long long idx, int dpt) {
    if (root == nullptr) return;
    if (dpt >= dp.size()) dp.emplace_back(0, ULONG_LONG_MAX);
    dp[dpt].first  = max(idx, dp[dpt].first);
    dp[dpt].second = min(idx, dp[dpt].second);
    ans            = max(ans, dp[dpt].first - dp[dpt].second + 1);
    dfs(root->left, 2 * idx, dpt + 1);
    dfs(root->right, 2 * idx + 1, dpt + 1);
  }

  int widthOfBinaryTree(TreeNode* root) {
    ans = 0;
    dfs(root, 1, 0);
    return ans;
  }
};