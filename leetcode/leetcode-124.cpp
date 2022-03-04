/*
 *@File Name          :leetcode-124.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/3 9:23
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
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
    int dfs(TreeNode *cur, int &ans) {
        if (cur == nullptr) return 0;
        int l = dfs(cur->left, ans);
        int r = dfs(cur->right, ans);
        if (l + r + cur->val > ans) ans = l + r + cur->val;
        if (l + cur->val > ans) ans = l + cur->val;
        if (r + cur->val > ans) ans = r + cur->val;
        if (cur->val > ans) ans = cur->val;
        return max(max(l, r), 0) + cur->val;
    }

    int maxPathSum(TreeNode *root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};