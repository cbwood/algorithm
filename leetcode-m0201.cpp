#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> se;
        if(head == NULL) return head;
        se.insert(head->val);
        ListNode* root = head, *tmp;
        tmp = root;
        root = root->next;
        while(root){
            if(se.count(root->val) == 0){
                se.insert(root->val);
                tmp->next = root;
                tmp = tmp->next;
            }else tmp->next = NULL;
            root = root->next;
        }return head;
    }
};


int main(){
    
    return 0;
}