/*
 *@File Name          :leetcode-w290-0.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/24 10:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>> &nums) {
        vector<int> cnt(1002, 0);
        for (auto &x: nums) {
            for (auto &y: x) {
                cnt[y]++;
            }
        }
        vector<int> ans;
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i] == nums.size())
                ans.emplace_back(i);
        }
        return ans;
    }
};