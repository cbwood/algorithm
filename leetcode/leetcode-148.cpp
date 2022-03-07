/*
 *@File Name          :leetcode-148.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/7 19:58
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
    ListNode *sortList(ListNode *head) {
        return sortList(head, nullptr);
    }

    ListNode *sortList(ListNode *head, ListNode *tail) {
        if (head == nullptr) return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast != tail) {
            fast = fast->next;
            slow = slow->next;
            if (fast != tail)
                fast = fast->next;
        }
        return mergeList(sortList(head, slow), sortList(slow, tail));
    }

    ListNode *mergeList(ListNode *l1, ListNode *l2) {
        ListNode *h = new ListNode();
        ListNode *ans = h;
        ListNode *t1 = l1, *t2 = l2;
        while (t1 != nullptr && t2 != nullptr) {
            if (t1->val <= t2->val) {
                h->next = t1;
                t1 = t1->next;
            } else {
                h->next = t2;
                t2 = t2->next;
            }
            h = h->next;
        }
        if (t1) h->next = t1;
        if (t2) h->next = t2;
        return ans->next;
    }
};