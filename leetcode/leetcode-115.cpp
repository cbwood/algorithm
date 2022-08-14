/*
 *@File Name          :leetcode-115.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/9 10:47
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  int numDistinct(string s, string t) {
    int                                n = s.size();
    int                                m = t.size();
    vector<vector<unsigned long long>> dp(n + 1,
                                          vector<unsigned long long>(m + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i + 1][j + 1] = dp[i][j + 1];
        if (s[i] == t[j]) dp[i + 1][j + 1] += dp[i + 1][j + 1];
      }
    }
    return dp[n][m];
  }
};