/*
 *@File Name          :leetcode-129.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/30 10:57
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

    void dfs(TreeNode *cur, int x) {
        if (cur == nullptr) {
            return;
        }
        if (!cur->left && !cur->right) {
            ans += x;
            return;
        }
        dfs(cur->left, x * 10 + cur->val);
        dfs(cur->right, x * 10 + cur->val);
    }

    int sumNumbers(TreeNode *root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};