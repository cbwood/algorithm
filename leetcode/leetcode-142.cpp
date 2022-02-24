/*
 *@File Name          :leetcode-142.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/24 10:22
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
#include "string"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast != slow) {
            if (fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast == nullptr) return nullptr;
        ListNode *p = head;
        while (p != slow) {
            p = p->next;
            slow = slow->next;
        }
        return slow;
    }
};