//
// Created by cb on 2021/9/13.
//

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return  true;
        ListNode *mid = findMid(head);
        ListNode *tail = reverseList(mid->next);
        while(tail != nullptr){
            if(head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }tail = reverseList(mid->next);
        return  true;
    }

    ListNode *reverseList(ListNode *head){
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur != nullptr){
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }return prev;
    }

    ListNode *findMid(ListNode *head){
        ListNode *fast = head, *slow = head;
        while(fast->next != nullptr && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }return slow;
    }
};

int main(){
    return 0;
}