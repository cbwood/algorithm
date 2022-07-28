/*
 *@File Name          :leetcode-198.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/28 9:24
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int         n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    if (n == 1) return dp[n - 1];
    dp[1] = max(dp[0], nums[1]);

    for (int i = 2; i < n; i++) dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    return dp[n - 1];
  }
};