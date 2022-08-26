/*
 *@File Name          :ubiquant2022-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/21 17:28
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int numberOfPairs(vector<int>& nums) {
    int           n = nums.size();
    vector<int>   a(n);
    map<int, int> ma;
    for (int i = 0; i < n; i++) {
      string t = to_string(nums[i]);
      std::reverse(t.begin(), t.end());
      a[i] = stoi(t) - nums[i];
      ma[a[i]]++;
    }

    long long ans = 0;
    int       mod = 1e9 + 7;

    for (auto& x : ma) {
      ans = (ans + 1LL * (x.second) * (x.second - 1) / 2) % mod;
    }
    return ans;
  }
};