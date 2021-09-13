#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode * he = head;
        while(head != NULL){
            head = head->next;
            k++;
        }
        if(n == k)
            return he->next;
        n = k-n;
        int num = 1;
        head = he;
        while(head != NULL){
            if(num == n){
                if(n == k)
                head->next = NULL;
                else head->next = head->next->next;
                return he;
            }num++;
            head = head->next;
        }
    }
};

int main(){
    Solution so;
    ListNode* he,*p;
    ListNode* h1;
    int n,k;
    h1 = new ListNode(1);
    he = h1;
    cin >> n >> k;
    while(n--){
        int x;
        cin >> x;
        p = new ListNode(x);
        h1->next = p;
        h1 = p;
    }
    ListNode* head = so.removeNthFromEnd(he,k);
    while(head != NULL){
        cout << head->val <<" ->";
        head = head->next;
    }
    return 0;
}