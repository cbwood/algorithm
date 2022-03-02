/*
 *@File Name          :leetcode-199.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/2 10:48
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

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

    void dfs(vector<int> &ans, int dept, TreeNode *cur) {
        if (cur == nullptr) return;
        if (ans.size() <= dept)
            ans.emplace_back(cur->val);
        dfs(ans, dept + 1, cur->right);
        if (ans[dept] == INT_MIN)
            ans[dept] = cur->val;
        dfs(ans, dept + 1, cur->left);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        dfs(ans, 0, root);
        return ans;
    }
};