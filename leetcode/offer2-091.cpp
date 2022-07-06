/*
 *@File Name          :offer2-091.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/4 15:21
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  int minCost(vector<vector<int>>& costs) {
    int n = costs.size();

    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        dp[i][j] =
            min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i][j];
      }
    }
    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
  }
};