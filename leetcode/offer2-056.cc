/*
 *@File Name          :offer2-056.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/17 9:31
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "map"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//class Solution {
//public:
//    bool dfs(TreeNode *l, TreeNode *r, int &k) {
//        if (l == nullptr || r == nullptr) return false;
//        if (l->val + r->val == k && l != r)
//            return true;
//        else if (l->val + r->val > k)
//            return dfs(l->left, r, k) || dfs(l, r->left, k);
//        return dfs(l->right, r, k) || dfs(l, r->right, k);
//    }
//
//    bool findTarget(TreeNode *root, int k) {
//        return dfs(root, root->right, k) || dfs(root->left, root, k);
//    }
//};

class Solution {
public:

    map<int, bool> ma;

    bool findTarget(TreeNode *root, int k) {
        if (root == nullptr)return false;
        if (ma[k - root->val])
            return true;
        ma[root->val] = true;
        if (findTarget(root->left, k)) return true;
        return findTarget(root->right, k);
    }
};