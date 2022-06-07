/*
 *@File Name          :offer2-078.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/7 8:30
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
  ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r) {
    if (l > r) return nullptr;
    if (l == r) return lists[l];
    int  mid = (l + r) / 2;
    auto l1  = mergeKLists(lists, l, mid);
    auto l2  = mergeKLists(lists, mid + 1, r);

    auto ans = new ListNode();
    auto tmp = ans;
    while (l1 && l2) {
      if (l1->val > l2->val) {
        tmp->next = l2;
        l2        = l2->next;
      } else {
        tmp->next = l1;
        l1        = l1->next;
      }
      tmp = tmp->next;
    }
    if (l1) tmp->next = l1;
    if (l2) tmp->next = l2;
    return ans->next;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    return mergeKLists(lists, 0, lists.size() - 1);
  }
};