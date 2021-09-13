#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *l=head, *r=head;
        while(r != NULL){
            if(r->val < x){
                l=l->next;
                swap(l->val, r->val);
            }r=r->next;
        }return head;
    }
};

int main(){
    
    return 0;
}