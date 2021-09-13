//
// Created by cb on 2021/9/13.
//

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
        if(head == nullptr) return nullptr;
        ListNode *fast = head, *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode *tmp = head;
                while(tmp != slow){
                    tmp = tmp->next;
                    slow = slow->next;
                }return slow;
            }
        }return nullptr;
    }
};

int main(){
    return 0;
}