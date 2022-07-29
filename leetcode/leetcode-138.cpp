/*
 *@File Name          :leetcode-138.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/29 9:55
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
  Node* copyNode(Node* cur) {
    Node* t   = new Node(cur->val);
    t->next   = cur->next;
    t->random = cur->random;
    return t;
  }

  Node* copyRandomList(Node* head) {
    Node* cur = head;

    while (cur) {
      cur->next = copyNode(cur);
      cur       = cur->next->next;
    }

    cur = head;
    while (cur) {
      if (cur->random) cur->next->random = cur->random->next;
      cur = cur->next->next;
    }

    cur      = head;
    auto ans = head->next;

    while (cur) {
      auto t = cur->next;

      if (cur->next) cur->next = cur->next->next;
      if (t->next) t->next = t->next->next;
      cur = cur->next;
    }
    return ans;
  }
};