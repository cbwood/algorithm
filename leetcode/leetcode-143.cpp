/*
 *@File Name          :leetcode-143.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/2 9:40
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
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
    void reorderList(ListNode *head) {
        if (head == nullptr) return;
        ListNode *cur = head;
        vector<ListNode *> vec;
        while (cur) {
            vec.push_back(cur);
            cur = cur->next;
        }
        int l = 0, r = vec.size() - 1;
        while (l < r) {
            vec[l]->next = vec[r];
            l++;
            if (l < r) {
                vec[r]->next = vec[l];
            }
            r--;
        }
        vec[l]->next = nullptr;
    }
};