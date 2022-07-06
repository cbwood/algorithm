/*
 *@File Name          :offer2-097.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 9:03
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    if (n < m) return 0;
    vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      dp[i][0] = 1;
      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[n][m];
  }
};