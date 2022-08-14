/*
 *@File Name          :leetcode-w305-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/7 10:41
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool validPartition(vector<int>& nums) {
    vector<int> dp(1000005, 0);
    for (auto& x : nums) dp[x]++;
    for (int i = 1; i < 1000005; i++) {
      if (dp[i] == 1) {
        int l = i, r = i;
        while (dp[r] == 1) r++;
        if ((r - l) % 3 == 1 && (dp[l - 1] <= 2 || dp[r] <= 0)) return false;
        if ((r - l) % 3 == 2 && (dp[l - 1] <= 2 && dp[r] <= 0)) return false;
        if ((r - l) % 3 == 1) {
          dp[r] -= 1;
          dp[l - 1] -= 1;
        }
        if ((r - l) % 3 == 2) {
          if (dp[l - 1] <= 2)
            dp[r] -= 1;
          else
            dp[l - 1] -= 1;
        }
        dp[r - 1] = 0;
        i         = r - 1;
      }
    }
    return true;
  }
};