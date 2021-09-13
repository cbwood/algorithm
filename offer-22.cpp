#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n = 0;
        ListNode* h = head;
        while(head)
            n++, head = head->next;
        n = n-k;
        while(n){
            n--;
            h = h->next;
        }return h;
    }
};

int main(){

    return 0;
}