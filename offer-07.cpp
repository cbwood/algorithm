#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
map<int, int> ma;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();
        for(int i = 0; i < m; ++i)
            ma[inorder[i]] = i;
        return building(preorder, inorder, 0, n-1, 0, m-1);
    }

    TreeNode * building(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl > pr||il > ir) return NULL;
        TreeNode *tmp = new TreeNode(preorder[pl]);
        int k = ma[preorder[pl]]-il;
        tmp->left = building(preorder, inorder, pl+1, pl+k,il, il+k-1);
        tmp->right = building(preorder, inorder, pl+k+1, pr, il+k+1, ir);
        return tmp;
    }
};


int main(){
    Solution so;
    return 0;
}