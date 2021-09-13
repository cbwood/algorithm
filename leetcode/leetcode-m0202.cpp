#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        int num = 0;
        ListNode *l = head, *r = head;
        while(k--){
            r = r->next;
        }while(r){
            r = r->next;
            l = l->next;
        }return l->val;
    }
};

int main(){
    
    return 0;
}