/*
 *@File Name          :leetcode-322-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/7 9:05
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "climits"
#include "vector"
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX / 2);
    dp[0] = 0;
    for (auto& x : coins) {
      for (int i = x; i <= amount; i++) dp[i] = min(dp[i - x] + 1, dp[i]);
    }
    if (dp[amount] == INT_MAX / 2) return -1;
    return dp[amount];
  }
};