/*
 *@File Name          :lccup-3.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/23 14:31
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int getMinimumTime(vector<int> &time, vector<vector<int>> &fruits, int limit) {
        int ans = 0;
        for (auto &x: fruits) {
            ans = ans + (x[1] + limit - 1) / limit * time[x[0]];
        }
        return ans;
    }
};