/*
 *@File Name          :leetcode-599.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/14 8:28
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "string"
#include "map"
#include "unordered_map"

using namespace std;


class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        unordered_map<string, int> ma;
        int n = list1.size();
        int m = list2.size();
        for (int i = 0; i < n; i++)
            ma[list1[i]] = i + 1;
        vector<string> ans;
        int maxn = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (ma[list2[i]]) {
                if (i + ma[list2[i]] < maxn) {
                    maxn = i + ma[list2[i]];
                    ans.clear();
                    ans.emplace_back(list2[i]);
                } else if (i + ma[list2[i]] == maxn) {
                    ans.emplace_back(list2[i]);
                }
            }

        }
        return ans;
    }
};