#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* dfs(Node *u, int k){
        if(u == NULL) return NULL;
        Node *lr = dfs(u->left, -1);
        Node* rg = dfs(u->right, 1);
        u->left = lr;
        if(lr != NULL) lr->right = u;
        u->right = rg;
        if(rg != NULL) rg->left = u;
        Node *ans = u;
        if(k == 1)
            while(ans->left != NULL)
                ans = ans->left;
        else while(ans->right != NULL)
                ans = ans->right;
        return ans;
    }
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return root;
        Node* head=root, *tmp = root;
        head = dfs(root, 1);
        tmp = head;
        while(tmp->right != NULL) tmp = tmp->right;
        head->left = tmp;
        tmp->right = head;
        return head;
    }
};