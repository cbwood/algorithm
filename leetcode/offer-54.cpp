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
    int tmp,ans;
    void dfs(TreeNode * u){
        if(tmp<=0) return ;
        dfs(u->left);
        tmp--;
        if(tmp == 0) 
            ans = u->val;
        dfs(u->right);
    }

    int kthLargest(TreeNode* root, int k) {
        tmp = k;
        dfs(root);
        return ans;
    }
};