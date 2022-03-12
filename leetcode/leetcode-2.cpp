/*
 *@File Name          :leetcode-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/12 9:01
 *@Description        :
 *@Function List      :
 *@History            :
 */


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x = 0;
        ListNode *head = new ListNode();
        ListNode *ans = head;
        while (l1 && l2) {
            l1->val = l1->val + l2->val + x;
            x = l1->val / 10;
            l1->val = l1->val % 10;
            head->next = l1;
            l1 = l1->next;
            l2 = l2->next;
            head = head->next;
        }
        while (l1) {
            l1->val += x;
            x = l1->val / 10;
            l1->val %= 10;
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }

        while (l2) {
            l2->val += x;
            x = l2->val / 10;
            l2->val %= 10;
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
        if (x) {
            ListNode *curx = new ListNode(x);
            head->next = curx;
        }
        return ans->next;
    }
};