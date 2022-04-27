/*
 *@File Name          :offer2-028.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/27 9:30
 *@Description        :
 *@Function List      :
 *@History            :
 */

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:

    void dfs(Node *&ans, Node *head) {
        if (head == nullptr)
            return;
        Node *cur = head;
        while (cur != nullptr) {
            ans->next = cur;
            cur->prev = ans;
            Node *t = cur->child;
            cur = cur->next;
            ans = ans->next;
            ans->child = nullptr;
            dfs(ans, t);
        }
        ans->next = nullptr;
    }

    Node *flatten(Node *head) {
        Node *ans = new Node();
        ans->prev = nullptr;
        Node *tmp = ans;
        dfs(ans, head);
        tmp = tmp->next;
        if (tmp != nullptr)
            tmp->prev = nullptr;
        return tmp;
    }
};