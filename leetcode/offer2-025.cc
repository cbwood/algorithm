/*
 *@File Name          :offer2-025.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/26 9:01
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

    int dfs(ListNode *l1, ListNode *l2, int d1, int d2) {
        if (l1 == nullptr || l2 == nullptr) return 0;
        if (d1 > d2) {
            int k = dfs(l1->next, l2, d1 - 1, d2);
            l1->val += k;
            k = l1->val / 10;
            l1->val %= 10;
            return k;
        } else {
            int k = dfs(l1->next, l2->next, d1 - 1, d2 - 1);
            l1->val += k + l2->val;
            k = l1->val / 10;
            l1->val %= 10;
            return k;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int d1 = 0, d2 = 0;
        ListNode *A = l1, *B = l2;
        while (A) {
            A = A->next;
            d1++;
        }
        while (B) {
            B = B->next;
            d2++;
        }
        if (d1 < d2) {
            swap(d1, d2);
            swap(l1, l2);
        }
        int k = dfs(l1, l2, d1, d2);
        while (k) {
            ListNode *pre = new ListNode(k, l1);
            l1 = pre;
            k = l1->val / 10;
            l1->val %= 10;
        }
        return l1;
    }
};