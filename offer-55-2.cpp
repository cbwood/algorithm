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

    int dfs(TreeNode *u){
        if(u == NULL) return 0;
        int l = dfs(u->left);
        int r = dfs(u->right);
        if(l == -1||r == -1) return -1;
        if(abs(r-l)>1) return -1;
        return max(l,r)+1;
    }

    bool isBalanced(TreeNode* root) {
        int k = dfs(root);
        return k==-1;
    }
};

int main(){

    return 0;
}