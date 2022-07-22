/*
 *@File Name          :leetcode-83.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/22 9:36
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "climits"

struct ListNode {
  int       val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    auto ans = head;
    while (head && head->next) {
      if (head->val == head->next->val) {
        head->next = head->next->next;
      } else
        head = head->next;
    }

    return ans;
  }
};