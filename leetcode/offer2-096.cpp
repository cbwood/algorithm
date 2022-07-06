/*
 *@File Name          :offer2-096.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/4 19:21
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size();
    int m = s2.size();
    int t = s3.size();
    if (m + n != t) return false;

    vector<bool> dp(m + 1, false);

    dp[0] = true;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++) {
        int p = i + j - 1;

        if (i) dp[j] = dp[j] && (dp[j] && s1[i - 1] == s3[p]);
        if (j) dp[j] = dp[j] || (dp[j - 1] && s2[j - 1] == s3[p]);
      }
    return dp[m];
  }
};