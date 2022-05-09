/*
 *@File Name          :offer2-043.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/9 9:14
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
public:
    CBTInserter(TreeNode *root) {
        vec_.reserve(5000);
        cur_pos_ = 0;
        vec_.push_back(root);
        while (cur_pos_ < vec_.size()) {
            if (vec_[cur_pos_]->right) {
                vec_.push_back(vec_[cur_pos_]->left);
                vec_.push_back(vec_[cur_pos_]->right);
                cur_pos_++;
            } else if (vec_[cur_pos_]->left) {
                vec_.push_back(vec_[cur_pos_]->left);
                break;
            } else {
                break;
            }
        }
    }

    int insert(int v) {
        int ans;
        if (vec_[cur_pos_]->left) {
            vec_[cur_pos_]->right = new TreeNode(v);
            vec_.push_back(vec_[cur_pos_]->right);
            ans = vec_[cur_pos_]->val;
            cur_pos_++;
        } else {
            vec_[cur_pos_]->left = new TreeNode(v);
            vec_.push_back(vec_[cur_pos_]->left);
            ans = vec_[cur_pos_]->val;
        }
        return ans;
    }

    TreeNode *get_root() {
        return *vec_.begin();
    }

private:
    int cur_pos_;
    std::vector<TreeNode *> vec_;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */