/*
 *@File Name          :leetcode-653.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/21 8:57
 *@Description        :
 *@Function List      :
 *@History            :
 */


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
    bool findTarget(TreeNode *root, int k) {
        return dfs(root, root, k);
    }

    bool dfs(TreeNode *l, TreeNode *r, int &k) {
        if (!(l && r)) return false;
        int t = l->val + r->val;
        if (t == k && l != r) return true;
        if (k > t) {
            if (dfs(l, r->right, k)) return true;
            return dfs(l->right, r, k);
        } else {
            if (dfs(l->left, r, k))
                return true;
            return dfs(l, r->left, k);
        }
    }
};