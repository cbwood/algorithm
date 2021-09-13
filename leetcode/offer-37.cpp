#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    int string2int(string st){
        int ans=0;
        int flag=1;
        int k=0;
        int n = st.length();
        if(st[0] == '-')
            flag=-1,k=1;
        for(;k<n;k++){
            ans = ans*10+st[k]-'0';
        }
        return ans*flag;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "[";
        if(root == NULL){
            ans = ans + "null"+"]";
            return ans;
        }
        else ans = ans + to_string(root->val);
        string nu = "null";
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* tmp = new TreeNode(0);
        while(!que.empty()){
            tmp = que.front();
            que.pop();
            if(tmp->left == NULL){
                ans = ans+","+nu;
            }else {
                que.push(tmp->left);
                ans = ans+","+to_string(tmp->left->val);
            }
            if(tmp->right == NULL){
                ans = ans+","+nu;
            }else {
                que.push(tmp->right);
                ans = ans+","+to_string(tmp->right->val);
            }
        }ans = ans +"]";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data.erase(0,1);
        int n = data.length();
        data.erase(n-1,1);
        vector<string> vec;
        string tmp = "";
        n = data.length();
        for(auto &x:data){
            if(x == ','){
                vec.push_back(tmp);
                tmp = "";
            }else tmp = tmp+x;
        }vec.push_back(tmp);
        n = vec.size();
        if(n == 1) return NULL;
        TreeNode *ans = new TreeNode(string2int(vec[0]));
        TreeNode *tmp1 = new TreeNode(string2int(vec[0]));
        TreeNode * root = ans;
        queue<TreeNode*> que;
        que.push(ans);
        for(int i = 1; i < n&&!que.empty(); ++i){
            tmp1 = que.front();
            que.pop();
            if(vec[i][0] == 'n'){
                tmp1->left = NULL;
            }else {
                ans = new TreeNode(string2int(vec[i]));
                tmp1->left = ans;
                que.push(ans);
            }i++;
            if(vec[i][0] == 'n'){
                tmp1->right = NULL;
            }else {
                ans = new TreeNode(string2int(vec[i]));
                tmp1->right = ans;
                que.push(ans);
            }
        }return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));