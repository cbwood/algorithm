/*
 *@File Name          :offer2-021.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/23 14:16
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *cur = new ListNode(0, head);
        ListNode *slow = cur, *fast = cur;
        ListNode *ans = cur;
        for (int i = 0; i <= n; i++)
            fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return ans->next;
    }
};