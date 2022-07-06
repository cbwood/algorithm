/*
 *@File Name          :offer2-089.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/4 14:52
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
      dp[i] = max(dp[i - 1], nums[i]);
      if (i >= 2) dp[i] = max(dp[i], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
  }
};