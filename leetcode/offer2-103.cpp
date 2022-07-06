/*
 *@File Name          :offer2-103.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 10:04
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include <climits>
#include "vector"
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;
    for (auto& x : coins) {
      for (int i = x; i <= amount; i++)
        if (dp[i - x] != INT_MAX) dp[i] = min(dp[i], dp[i - x] + 1);
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};