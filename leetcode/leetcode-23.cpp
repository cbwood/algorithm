/*
 *@File Name          :leetcode-23.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/25 9:07
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "string"
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return dfs(0, lists.size() - 1, lists);
    }

    ListNode *dfs(int l, int r, vector<ListNode *> &lists) {
        if (l > r) return nullptr;
        if (r == l) return lists[l];
        int mid = (r + l) / 2;
        ListNode *t1 = dfs(l, mid, lists);
        ListNode *t2 = dfs(mid + 1, r, lists);
        ListNode *ans = new ListNode();
        ListNode *anss = ans;
        while (t1 && t2) {
            if (t1->val < t2->val) {
                ans->next = t1;
                t1 = t1->next;
            } else {
                ans->next = t2;
                t2 = t2->next;
            }
            ans = ans->next;
        }
        if (t1) {
            ans->next = t1;
        }
        if (t2) {
            ans->next = t2;
        }
        return anss->next;
    }
};