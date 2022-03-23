/*
 *@File Name          :leetcode-144.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/23 10:46
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"

using namespace std;


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
    vector<int> ans;

    vector<int> preorderTraversal(TreeNode *root) {
        if (root == nullptr) return ans;
        ans.emplace_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};