/*
 *@File Name          :offer2-024.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/26 8:54
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        while (head) {
            ListNode *tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};