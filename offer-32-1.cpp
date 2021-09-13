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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> ans;
        if(root == NULL) return ans;
        que.push(root);
        TreeNode* tmp;
        while(!que.empty()){
            tmp = que.front();
            ans.push_back(tmp->val);
            que.pop();
            if(tmp->left != NULL)
                que.push(tmp->left);
            if(tmp->right != NULL)
                que.push(tmp->right);
        }return ans;
    }
};


int main(){
    return 0;
}