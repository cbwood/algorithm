/*
 * @File Name          :leetcode-25.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/3 14:05
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "algorithm"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sumk = 0;
        ListNode* cur = head;
        while (cur){
            sumk++;
            cur = cur->next;
        }
        cur = head;
        int curk = 0;
        head = nullptr;
        ListNode* tail = cur, *ans = new ListNode();
        while(sumk - curk >= k){
            for(int i = 0; i < k; i++)
                tail = tail->next;
            ListNode* t = dfs(cur, nullptr, 0, k);
            if(head == nullptr) head = t, ans = t;
            else head->next = t;
            while(head->next){
                head = head->next;
            }
            head->next = tail;
            cur = head->next;
            tail = cur;
            curk += k;
        }return ans;
    }

    ListNode* dfs(ListNode* cur, ListNode* pre, int l, int &r){
        if(l >= r) return pre;
        if(cur == nullptr) return pre;
        ListNode* t = dfs(cur->next, cur, l+1, r);
        cur->next = pre;
        return t;
    }
};