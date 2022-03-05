/*
 *@File Name          :leetcode-82.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/5 9:25
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return head;
        ListNode *ans = new ListNode(-101, head);
        ListNode *cur = ans;
        cur->next = nullptr;
        ListNode *tmp = nullptr;
        ListNode *d = nullptr;
        int prex = -101;
        while (head) {
            bool check = true;
            while (head && (head->val == prex || (head->next && head->next->val == head->val))) {
                d = head;
                prex = head->val;
                head = head->next;
                // delete d;
                check = false;
            }
            if (check) {
                cur->next = head;
                head = head->next;
                cur = cur->next;
                cur->next = nullptr;
            }

        }
        return ans->next;
    }
};

};