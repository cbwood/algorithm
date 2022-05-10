/*
 *@File Name          :offer2-045.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/10 8:55
 *@Description        :
 *@Function List      :
 *@History            :
 */

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
    int findBottomLeftValue(TreeNode *root) {
        int ans = -1;
        queue<TreeNode *> que;
        que.emplace(root);
        while (!que.empty()) {
            int sz = que.size();
            for (int i = 0; i < sz; ++i) {
                auto node = que.front();
                que.pop();
                if (i == 0)
                    ans = node->val;
                if (node->left) {
                    que.emplace(node->left);
                }
                if (node->right)
                    que.emplace(node->right);
            }
        }
        return ans;
    }
};
