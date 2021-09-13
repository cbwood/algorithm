#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(TreeNode *u, int sumx, int k){
        if(u == NULL){
            if(sumx == 0&&k)
                ans.push_back(tmp);
            return;
        }tmp.push_back(u->val);
        dfs(u->left, sumx-u->val,0);
        if(u->left != NULL|u->right != NULL) dfs(u->right, sumx-u->val, u->left == NULL);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        tmp.clear();
        if(root == NULL) return ans;
        dfs(root, sum,0);
        return ans;
    }
};