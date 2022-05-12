/*
 *@File Name          :offer2-050.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/12 9:01
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

class Solution {
public:
    map<int, int> ma;
    int ans = 0;

    void dfs(TreeNode *root, int sumx, const int &target) {
        if (root == nullptr)
            return;
        int tmp = sumx + root->val;

        ans += ma[tmp - target];
        ma[tmp]++;
        dfs(root->left, tmp, target);
        dfs(root->right, tmp, target);
        ma[tmp]--;
    }

    int pathSum(TreeNode *root, int targetSum) {
        ma[0] = 1;
        dfs(root, 0, targetSum);
        return ans;
    }
};