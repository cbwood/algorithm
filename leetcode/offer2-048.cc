/*
 *@File Name          :offer2-048.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/11 9:02
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "queue"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    int k = 0;
    // Encodes a tree to a single string.

    void dfs1(string &ans, TreeNode *root) {
        if (root == nullptr) {
            ans += "null,";
            return;
        }
        ans += to_string(root->val) + ",";
        dfs1(ans, root->left);
        dfs1(ans, root->right);
    }

    string serialize(TreeNode *root) {
        string ans;
        dfs1(ans, root);
        ans = ans.substr(0, ans.size() - 1);
        while (ans.size() > 4 && ans.substr(ans.size() - 4, 4) == "null")
            ans = ans.substr(0, ans.size() - 5);
        return ans;
    }

    TreeNode *dfs(string &data) {
        if (k >= data.size()) {
            return nullptr;
        }
        int pos = data.find(',', k);
        if (pos == -1) pos = data.size();
        if (data.substr(k, pos - k) == "null") {
            k = pos + 1;
            return nullptr;
        } else {
            int v = stoi(data.substr(k, pos - k));
            auto *t = new TreeNode(v);
            k = pos + 1;
            t->left = dfs(data);
            t->right = dfs(data);
            return t;
        }
        return nullptr;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {

        return dfs(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));