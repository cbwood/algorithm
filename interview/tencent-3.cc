/*
 *@File Name          :tencent-3.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/24 20:43
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param a ListNode类vector 指向每段碎片的开头
     * @return ListNode类
     */
    const int maxn = 1e6;

    ListNode *solve(vector<ListNode *> &a) {
        // write code here
        map<int, int> ma;
        map<int, ListNode *> mb;
        vector<int> v(maxn, -1);
        int n = a.size();
        int minx = INT_MAX;
        int idx = 1;
        for (int i = 0; i < n; i++)
            if (a[i]) {
                ListNode *tmp = a[i];
                minx = min(minx, tmp->val);
                int prex = tmp->val;
                if (ma[tmp->val] == 0) {
                    ma[tmp->val] = idx++;
                    mb[idx - 1] = tmp;
                }
                tmp = tmp->next;
                while (tmp) {
                    if (ma[tmp->val] == 0) {
                        ma[tmp->val] = idx++;
                        mb[idx - 1] = tmp;
                    }
                    v[ma[prex]] = ma[tmp->val];
                    minx = min(minx, tmp->val);
                    prex = tmp->val;
                    tmp = tmp->next;
                }
            }


        int cur = v[ma[minx]];
        ListNode *ans = mb[ma[minx]];
        ListNode *tmp = ans;
        while (cur != ma[minx] && cur != -1) {
            tmp->next = mb[cur];
            tmp = tmp->next;
            cur = v[cur];
        }
        tmp->next = nullptr;
        if (ans->next->val < tmp->val) {
            return ans;
        }
        tmp = ans->next;
        ListNode *prex = nullptr;
        while (tmp) {
            ListNode *t = tmp->next;
            tmp->next = prex;
            prex = tmp;
            tmp = t;
        }
        ans->next = prex;
        return ans;
    }
};