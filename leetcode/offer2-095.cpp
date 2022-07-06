/*
 *@File Name          :offer2-095.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/4 19:08
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(2, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (text1[i] == text2[j]) {
          if (i == 0 || j == 0)
            dp[i & 1][j] = 1;
          else
            dp[i & 1][j] = dp[1 - (i & 1)][j - 1] + 1;
        }
        if (i) dp[i & 1][j] = max(dp[i & 1][j], dp[1 - (i & 1)][j]);
        if (i * j) dp[i & 1][j] = max(dp[i & 1][j], dp[1 - (i & 1)][j - 1]);
        if (j) dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1][j - 1]);
      }
    return dp[(n - 1) & 1][m - 1];
  }
};