/*
 *@File Name          :offer2-099.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 9:30
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
  int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (i && dp[i - 1][j] < dp[i][j]) dp[i][j] = dp[i - 1][j];
        if (j && dp[i][j - 1] < dp[i][j]) dp[i][j] = dp[i][j - 1];
        dp[i][j] += grid[i][j];
      }
    return dp[n - 1][m - 1];
  }
};