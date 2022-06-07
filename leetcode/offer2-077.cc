/*
 *@File Name          :offer2-077.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/7 8:14
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
using namespace std;

struct ListNode {
  int       val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    auto fast = head, slow = head;
    auto pre = head;
    while (fast) {
      fast = fast->next;
      pre  = slow;
      slow = slow->next;
      if (fast) fast = fast->next;
    }
    pre->next = nullptr;
    auto l    = sortList(head);
    auto r    = sortList(slow);
    auto ans  = new ListNode();
    auto tmp  = ans;
    while (l && r) {
      if (l->val > r->val) {
        tmp->next = r;
        r         = r->next;
      } else {
        tmp->next = l;
        l         = l->next;
      }
      tmp = tmp->next;
    }
    while (l) {
      tmp->next = l;
      tmp       = tmp->next;
      l         = l->next;
    }
    while (r) {
      tmp->next = r;
      tmp       = tmp->next;
      r         = r->next;
    }
    tmp->next = nullptr;
    return ans->next;
  }
};