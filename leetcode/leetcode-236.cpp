/*
 * @File Name          :leetcode-236.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/27 10:15
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if (l && r) return root;
        if (l) return l;
        if (r) return r;
        return nullptr;
    }
};