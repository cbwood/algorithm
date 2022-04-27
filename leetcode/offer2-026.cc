/*
 *@File Name          :offer2-026.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/27 8:57
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"

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
        vector<ListNode *> vec;
        ListNode *cur = head;
        while (cur != nullptr) {
            vec.emplace_back(cur);
            cur = cur->next;
        }
        int l = 0, r = static_cast<int>(vec.size()) - 1;
        while (l < r) {
            vec[l]->next = vec[r];
            l++;
            if (l == r) break;
            vec[r]->next = vec[l];
            r--;
        }
        vec[l]->next = nullptr;
    }
};