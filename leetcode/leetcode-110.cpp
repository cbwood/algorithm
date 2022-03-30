/*
 *@File Name          :leetcode-110.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/30 11:02
 *@Description        :
 *@Function List      :
 *@History            :
 */

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
    bool flag;

    int dfs(TreeNode *cur) {
        if (cur == nullptr || !flag) return 0;
        int l = dfs(cur->left);
        int r = dfs(cur->right);
        if (abs(r - l) > 1) {
            flag = false;
            return 0;
        }
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode *root) {
        flag = true;
        dfs(root);
        return flag;
    }
};