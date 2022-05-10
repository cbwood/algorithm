/*
 *@File Name          :offer2-046.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/10 9:00
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "queue"

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
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> que;
        if (root)
            que.emplace(root);
        vector<int> ans;
        while (!que.empty()) {
            int sz = que.size();
            int tmp = 0;
            while (sz--) {
                auto node = que.front();
                que.pop();
                tmp = node->val;
                if (node->left)
                    que.emplace(node->left);
                if (node->right)
                    que.emplace(node->right);
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};