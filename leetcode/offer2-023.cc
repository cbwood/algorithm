/*
 *@File Name          :offer2-023.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/25 9:30
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        while (ptrB != ptrA) {
            if (ptrB == nullptr)
                ptrB = headA;
            else ptrB = ptrB->next;
            if (ptrA == nullptr)
                ptrA = headB;
            else ptrA = ptrA->next;
        }
        return ptrB;
    }
};