/*
 *@File Name          :leetcode-234.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/14 10:08
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
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
  ListNode* reverse(ListNode* head) {
    ListNode* pre = nullptr;
    while (head) {
      auto tmp   = head->next;
      head->next = pre;
      pre        = head;
      head       = tmp;
    }
    return pre;
  }
  bool isPalindrome(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast) {
      fast = fast->next;
      slow = slow->next;
      if (fast) fast = fast->next;
    }
    slow = reverse(slow);
    while (head && slow) {
      if (head->val != slow->val) return false;
      head = head->next;
      slow = slow->next;
    }
    return true;
  }
};