/*
 * @File Name          :leetcode-103.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/25 10:05
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"
#include "deque"

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
    vector<vector<int>> ans;

    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        ans.clear();
        dfs(0, root);
        for (int i = 1; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }

    void dfs(int d, TreeNode *cur) {
        if (cur == nullptr) return;
        if (ans.size() == d) ans.emplace_back();
        ans[d].push_back(cur->val);
        dfs(d + 1, cur->left);
        dfs(d + 1, cur->right);
    }
};