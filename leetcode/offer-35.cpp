/*
 *@File Name          :offer-35.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/13 9:04
 *@Description        :
 *@Function List      :
 *@History            :
 */

class Node {
 public:
  int   val;
  Node* next;
  Node* random;

  Node(int _val) {
    val    = _val;
    next   = nullptr;
    random = nullptr;
  }
};

class Solution {
 public:
  Node* copy(Node* cur) {
    Node* t   = new Node(cur->val);
    t->next   = cur->next;
    t->random = cur->random;
    return t;
  }

  Node* copyRandomList(Node* head) {
    if (head == nullptr) return head;
    Node* t = head;
    while (t) {
      t->next = copy(t);
      t       = t->next->next;
    }
    t    = head;
    head = head->next;
    while (head) {
      if (head->random) head->random = head->random->next;
      if (head->next == nullptr) break;
      head = head->next->next;
    }
    head = t;
    t    = t->next;
    while (head) {
      auto tmp   = head->next;
      head->next = head->next->next;
      if (tmp->next) tmp->next = tmp->next->next;
      head = head->next;
    }

    return t;
  }
};