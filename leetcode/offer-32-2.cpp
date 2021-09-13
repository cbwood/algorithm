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
    void dfs(int d, TreeNode* u,vector<vector<int>> &ans){
        if(u == NULL) return;
        while(ans.size()<= d) ans.push_back(vector<int>{});
        ans[d].push_back(u->val);
        dfs(d+1, u->left, ans);
        dfs(d+1, u->right,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(0,root, ans);
        return ans;
    }
};

int main(){
    
    return 0;
}