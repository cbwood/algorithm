/*
 * @File Name          :leetcode-160.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/23 10:49
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a != nullptr ? a->next : headB;
            b = b != nullptr ? b->next : headA;
        }
        return a;
    }
};