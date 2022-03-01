/*
 *@File Name          :leetcode-94.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/1 9:12
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "string"

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

    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        dfs(root);
        return ans;
    }
};