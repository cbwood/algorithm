/*
 *@File Name          :leetcode-297.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/1 9:53
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "sstream"
#include "string"
#include "vector"
using namespace std;

struct TreeNode {
  int       val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) return "#";
    return to_string(root->val) + " " + serialize(root->left) + " " +
           serialize(root->right);
  }

  TreeNode* dfs(istringstream& ss) {
    string t;
    ss >> t;
    if (t == "#") return nullptr;
    TreeNode* root = new TreeNode(stoi(t));
    root->left     = dfs(ss);
    root->right    = dfs(ss);
    return root;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream ss(data);
    return dfs(ss);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));