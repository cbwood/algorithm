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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int k = 0;
        ListNode *root = new ListNode(0);
        ListNode *ans = root;
        while(l1 || l2 || k){
            int sum = 0;
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += k;
            k = sum/10;
            ans ->next = new ListNode(sum%10);
            ans = ans->next;
        }
        return root->next;
    }
};

int main(){
    return 0;
}