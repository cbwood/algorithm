#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* dfs(ListNode* pre, ListNode* cur){
        ListNode* ans;
        if(cur == NULL) return cur;
        if(cur->next == NULL){
            ans = cur;
        }else ans = dfs(cur, cur->next);
        cur->next = pre;
        return ans;
    }
    ListNode* reverseList(ListNode* head) {
        return dfs(NULL, head);
    }
};

int main(){

    return 0;
}