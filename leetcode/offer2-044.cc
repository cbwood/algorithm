/*
 *@File Name          :offer2-044.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/9 9:42
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include <climits>
#include "algorithm"
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
    vector<int> largestValues(TreeNode *root) {
        vector<int> ans;
        queue<TreeNode *> que;
        if (root)
            que.push(root);
        while (!que.empty()) {
            int sz = que.size();
            int maxv = INT_MIN;
            for (int i = 0; i < sz; ++i) {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
                maxv = max(maxv, cur->val);
            }
            ans.emplace_back(maxv);
        }
        return ans;
    }
};