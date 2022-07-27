/*
 *@File Name          :leetcode-512.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/26 9:49
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int                  n = nums.size();
    vector<vector<int> > dp(2, vector<int>(2, 0));
    dp[0][0] = dp[0][1] = nums[0];
    int ans             = nums[0];
    for (int i = 1; i < n; i++) {
      dp[i & 1][0] =
          max(dp[(i - 1) & 1][0] * nums[i], dp[(i - 1) & 1][1] * nums[i]);
      dp[i & 1][1] =
          min(dp[(i - 1) & 1][0] * nums[i], dp[(i - 1) & 1][1] * nums[i]);
      dp[i & 1][0] = max(dp[i & 1][0], nums[i]);
      dp[i & 1][1] = min(dp[i & 1][1], nums[i]);
      ans          = max(ans, dp[i & 1][0]);
    }
    return ans;
  }
};