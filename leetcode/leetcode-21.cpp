#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        int x;
        ListNode *p, *ans;
        if(!l1 && !l2) return NULL;
        if(l2 == NULL || (l1&&l1->val < l2->val)){
            x = l1->val;
            l1 = l1->next;
        }else {
            x = l2->val;
            l2 = l2->next;
        }p = new ListNode(x);
        ans = p;
        while(l1 && l2){
            if(l1->val < l2->val){
                x = l1->val;
                l1 = l1->next;
            }else {
                x = l2->val;
                l2 = l2->next;
            }ListNode *s = new ListNode(x);
            p->next = s;
            p = s;
        }while(l1){
            ListNode *s = new ListNode(l1->val);
            l1 = l1->next;
            p->next = s;
            p = s;
        }
        while(l2){
            ListNode *s = new ListNode(l2->val);
            l2 = l2->next;
            p->next = s;
            p = s;
        }
        return ans;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    ListNode *l1,*l2,*h1,*h2;
    l1 = new ListNode(1);
    h1 = l1;
    l2 = new ListNode(1);
    h2 = l2;
    while(n--){
        int x;
        cin >> x;
        ListNode *p = new ListNode(x);
        h1->next = p;
        h1 = p;
    }
    while(m--){
        int x;
        cin >> x;
        ListNode *p = new ListNode(x);
        h2->next = p;
        h2 = p;
    }
    Solution so;
    ListNode *h = so.mergeTwoLists(l1, l2);
    while(h){
        cout << h->val << "->";
        h = h->next;
    }
    return 0;
}