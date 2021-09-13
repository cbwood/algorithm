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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> tmp;
        deque<TreeNode*> dq;
        dq.push_front(root);
        int n,p;
        TreeNode * t;
        while(!dq.empty()){
            n = dq.size();
            p = ans.size()&1;
            tmp.clear();
            for(int i = 0; i < n; ++i){
                if(p){
                    t = dq.front();
                    dq.pop_front();
                    tmp.push_back(t->val);
                    if(t->left) dq.push_back(t->left);
                    if(t->right) dq.push_back(t->right);
                }else{
                    t = dq.back();
                    dq.pop_back();
                    tmp.push_back(t->val);
                    if(t->right) dq.push_front(t->right);
                    if(t->left) dq.push_front(t->left);
                }
            }ans.push_back(tmp);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}