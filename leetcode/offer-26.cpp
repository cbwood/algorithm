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
    bool ismatch(TreeNode *A, TreeNode *B){
        if(B == NULL) return true;
        if(A == NULL && B != NULL) return false;
        if(A->val != B->val) return false;
        return ismatch(A->left, B->left) && ismatch(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL||A == NULL) return false;
        if(A->val == B->val){
            if(ismatch(A, B))
                return true;
        }
        bool t1 = isSubStructure(A->left, B);
        bool t2 = isSubStructure(A->right, B);
        return t1||t2;
    }
};