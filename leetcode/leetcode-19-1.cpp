/*
 *@File Name          :leetcode-19-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/5 9:16
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
        ListNode *fast = head;
        ListNode *du = new ListNode(0, head);
        while (n--) {
            fast = fast->next;
        }
        ListNode *slow = du;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return du->next;
    }
};