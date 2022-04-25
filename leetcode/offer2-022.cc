/*
 *@File Name          :offer2-022.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/25 9:14
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
            if (fast == nullptr)
                return nullptr;
            fast = fast->next;
            if (fast == slow) {
                ListNode *tmp = head;
                while (tmp != fast) {
                    tmp = tmp->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};