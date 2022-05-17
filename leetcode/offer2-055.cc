/*
 *@File Name          :offer2-055.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/17 8:59
 *@Description        :
 *@Function List      :
 *@History            :
 */
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

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        add(root);
    }

    void add(TreeNode *root) {
        while (root) {
            sta_.emplace(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode *ans = sta_.top();;
        sta_.pop();
        if (ans->right) {
            add(ans->right);
        }
        return ans->val;
    }

    bool hasNext() {
        return !sta_.empty();
    }

private:
    stack<TreeNode *> sta_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */