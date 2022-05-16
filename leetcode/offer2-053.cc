
/*
 *@File Name          :offer2-053.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/14 8:47
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include <cstdio>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    TreeNode *ans = nullptr;
//
//    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
//        if (root == nullptr)
//            return nullptr;
//
//        TreeNode *r = inorderSuccessor(root->right, p);
//        if (r)
//            return r;
//        if (root == p)
//            return ans;
//        ans = root;
//        TreeNode *l = inorderSuccessor(root->left, p);
//        return l;
//    }
//};

class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *ans = nullptr;
        TreeNode *cur;
        if (p->right) {
            cur = p->right;
            while (cur->left)
                cur = cur->left;
            return cur;
        }
        cur = root;
        while (cur) {
            if (cur->val > p->val) {
                ans = cur;
                cur = cur->left;
            } else cur = cur->right;
        }
        return ans;
    }
};