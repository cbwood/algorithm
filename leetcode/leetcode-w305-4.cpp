/*
 *@File Name          :leetcode-w305-4.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/7 10:34
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int longestIdealString(string s, int k) {
    vector<int> dp(30, 0);
    int         ans = 0;
    for (auto& x : s) {
      int t   = x - 'a';
      int tmp = dp[t];
      for (int i = 0; i < 26; i++) {
        if (abs(i - t) <= k && i != t) { dp[t] = max(dp[t], dp[i] + 1); }
      }
      dp[t] = max(dp[t], tmp + 1);
      ans   = max(ans, dp[t]);
    }
    return ans;
  }
};