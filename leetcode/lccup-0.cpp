/*
 *@File Name          :lccup-0.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/16 14:53
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int giveGem(vector<int> &gem, vector<vector<int>> &operations) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (auto &x: operations) {
            int k = gem[x[0]] / 2;
            gem[x[0]] -= k;
            gem[x[1]] += k;
        }
        for (auto &x: gem) {
            maxi = max(maxi, x);
            mini = min(mini, x);
        }
        return maxi - mini;
    }
};