/*
 * @File Name          :leetcode-102.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/8 15:46
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"
#include "queue"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<pair<TreeNode*, int>> que;
        vector<int> tmp;
        int pre=0;
        que.push(make_pair(root, 0));
        while (!que.empty()){
            pair<TreeNode*, int> pa = que.front();
            que.pop();
            if(pa.second != pre){
                ans.push_back(tmp);
                tmp.clear();
                pre = pa.second;
            }tmp.push_back(pa.first->val);

            if(pa.first->left){
                que.push(make_pair(pa.first->left, pa.second+1));
            }
            if(pa.first->right){
                que.push(make_pair(pa.first->right, pa.second+1));
            }
        }
        return ans;
    }
};