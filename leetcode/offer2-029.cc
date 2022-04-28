/*
 *@File Name          :offer2-029.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/28 8:58
 *@Description        :
 *@Function List      :
 *@History            :
 */


class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node *_next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node *insert(Node *head, int insertVal) {
        Node *cur = head;
        Node *insert_node = new Node(insertVal);
        if (cur == nullptr) {
            insert_node->next = insert_node;
            return insert_node;
        }
        while (cur) {
            if (cur->val <= insertVal && cur->next->val >= insertVal) {
                break;
            }
            if (cur->val <= insertVal && cur->next->val <= insertVal && cur->val > cur->next->val) {
                break;
            }
            if (cur->val >= insertVal && cur->next->val >= insertVal && cur->val > cur->next->val) {
                break;
            }
            if (cur->next == head) break;
            cur = cur->next;
        }
        insert_node->next = cur->next;
        cur->next = insert_node;
        return head;
    }
};