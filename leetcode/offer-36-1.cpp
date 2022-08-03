/*
 *@File Name          :offer-36-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/2 10:10
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "climits"
#include "vector"
using namespace std;

class Node {
 public:
  int   val;
  Node* left;
  Node* right;

  Node() {}

  Node(int _val) {
    val   = _val;
    left  = NULL;
    right = NULL;
  }

  Node(int _val, Node* _left, Node* _right) {
    val   = _val;
    left  = _left;
    right = _right;
  }
};

class Solution {
 public:
  Node* post = nullptr;

  void dfs(Node* root) {
    if (root == nullptr) return;
    dfs(root->right);
    root->right = post;
    post        = root;
    dfs(root->left);
  }

  Node* treeToDoublyList(Node* root) {
    if (root == nullptr) return nullptr;
    dfs(root);
    Node* cur = post;
    while (cur->right) {
      cur->right->left = cur;
      cur              = cur->right;
    }
    cur->right = post;
    post->left = cur;
    return post;
  }
};