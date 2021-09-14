//
// Created by cb on 2021/9/14.
//

#include "vector"
#include "deque"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> BSTSequences(TreeNode *root) {
//        deque<TreeNode*> dq;
        if(root == nullptr) return {{}};
        dq.push_back(root);
        dfs();
        return ans;
    }

    void dfs(){
        if(dq.empty()){
            ans.push_back(path);
            return;
        }
        int n = dq.size();
        for(int i = 0; i < n; i++){
            TreeNode* t = dq.front();
            dq.pop_front();
            path.push_back(t->val);

            if(t->left != nullptr) dq.push_front(t->left);
            if(t->right != nullptr) dq.push_front(t->right);

            dfs();

            if(t->left != nullptr) dq.pop_front();
            if(t->right != nullptr) dq.pop_front();

            dq.push_back(t);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> path;
    deque<TreeNode*> dq;
};