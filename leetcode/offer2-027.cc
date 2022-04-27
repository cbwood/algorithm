/*
 *@File Name          :offer2-027.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/27 9:12
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
    ListNode *reverse_list(ListNode *cur) {
        ListNode *pre = nullptr;
        while (cur != nullptr) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    bool isPalindrome(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
            if (fast == nullptr)
                break;
            fast = fast->next;
        }

        ListNode *r = reverse_list(slow);
        ListNode *l = head;
        while (l != nullptr && r != nullptr) {
            if (l->val != r->val) return false;
            l = l->next;
            r = r->next;
        }
        return true;
    }
};