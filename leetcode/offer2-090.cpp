/*
 *@File Name          :offer2-090.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/4 15:01
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
    if (n == 1) return nums.back();
    if (n == 2) return max(nums[0], nums[1]);

    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n - 1; i++) dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    int ans = dp[n - 2];

    dp[0] = nums[1];
    dp[1] = max(nums[2], nums[1]);
    for (int i = 2; i < n - 1; i++)
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + 1]);
    ans = max(ans, dp[n - 2]);
    return ans;
  }
};