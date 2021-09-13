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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a != b){
            a = a!= nullptr ? a->next: headB;
            b = b!= nullptr ? b->next: headA;
        }return a;
    }
};

int main(){
    return 0;
}