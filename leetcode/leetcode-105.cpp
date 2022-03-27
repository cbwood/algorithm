/*
 *@File Name          :leetcode-105.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/26 21:36
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
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

class Solution {
public:
    map<int, int> ma;
    int k;

    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int l, int r) {
        if (l > r) return nullptr;
        TreeNode *t = new TreeNode(preorder[k]);
        int mid = ma[preorder[k++]];
        t->left = dfs(preorder, inorder, l, mid - 1);
        t->right = dfs(preorder, inorder, mid + 1, r);
        return t;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++)
            ma[inorder[i]] = i;
        k = 0;
        return dfs(preorder, inorder, 0, preorder.size() - 1);
    }
};