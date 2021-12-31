//
// Created by cb on 2021/12/29.
//

#include "algorithm"
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        if(head == nullptr) return head;
        while(head->next != nullptr){
            ListNode* cur = head;
            head = head->next;
            cur->next = pre;
            pre = cur;
        }
        head->next = pre;
        return head;
    }
};