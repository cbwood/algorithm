//
// Created by cb on 2021/9/13.
//
#include "vector"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ans;
        dfs(ans, tree, 0);
        return ans;
    }

    void dfs(vector<ListNode*> &ans, TreeNode *root, int dept){
        if(root == nullptr) return;
        if(ans.size() <= dept) {
            ListNode *k = new ListNode(root->val);
            ans.push_back(k);
        }else {
            ListNode *tmp = ans[dept];
            while(tmp->next != nullptr) tmp = tmp->next;
            tmp->next = new ListNode(root->val);
        }
        dfs(ans, root->left, dept+1);
        dfs(ans, root->right, dept+1);
    }
};