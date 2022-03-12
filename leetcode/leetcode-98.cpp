/*
 *@File Name          :leetcode-98.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/10 14:48
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "vector"
#include "algorithm"
#include "stack"

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
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> st;
        long long pre = LONG_LONG_MIN;
        while (root || !st.empty()) {
            while (root) {
                st.emplace(root);
                root = root->left;
            }
            root = st.top();
            if (root->val <= pre)
                return false;
            pre = root->val;
            st.pop();
            root = root->right;
        }
        return true;
    }
};