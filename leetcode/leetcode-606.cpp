/*
 *@File Name          :leetcode-606.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/19 8:57
 *@Description        :
 *@Function List      :
 *@History            :
 */

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
    string tree2str(TreeNode *root) {
        if (root == nullptr) return "";

        string ans = to_string(root->val);
        if (root->left || root->right) {
            ans += "(" + tree2str(root->left) + ")";
            if (root->right) {
                ans += "(" + tree2str(root->right) + ")";
            }
        }
        return ans;
    }
};