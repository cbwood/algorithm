/*
 *@File Name          :offer2-051.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/13 9:01
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "climits"
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
        int tmp = root->val;
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);
        ans = max(ans, tmp + l + r);
        return tmp + max(l, r);
    }

    int maxPathSum(TreeNode *root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};