/*
 *@File Name          :leetcode-543.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/2 11:03
 *@Description        :
 *@Function List      :
 *@History            :
 */


#include "vector"
#include "algorithm"

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
    int ans;

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans = max(ans, l + r + 1);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        ans = 0;
        dfs(root);
        return ans - 1;
    }
};