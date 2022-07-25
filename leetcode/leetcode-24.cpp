/*
 *@File Name          :leetcode-24.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/23 9:30
 *@Description        :
 *@Function List      :
 *@History            :
 */

struct ListNode {
  int       val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* h = new ListNode(0, head);
    if (head == nullptr || head->next == nullptr) return head;
    auto ans = head->next;
    while (head && head->next) {
      auto t           = head->next->next;
      h->next          = head->next;
      h                = head;
      head->next->next = head;
      head->next       = t;
      head             = t;
    }
    return ans;
  }
};