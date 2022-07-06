/*
 *@File Name          :offer2-104.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 10:10
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include <climits>
#include "vector"
using namespace std;

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
      for (auto& x : nums) {
        if (i >= x && dp[i - x] < INT_MAX - dp[i]) dp[i] += dp[i - x];
      }
    }
    return dp[target];
  }
};