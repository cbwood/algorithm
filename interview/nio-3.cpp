/*
 *@File Name          :nio-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/13 19:09
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int                 mod = 1e9 + 7;
  vector<vector<int>> dp(201, vector<int>(201, 0));
  dp[0][0] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 0; j <= k; j++) {
      for (int x = max(j - i + 1, 0); x <= j; x++) { dp[i][j] += dp[i - 1][x]; }
    }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++)
      for (int p = 0; p <= k - i - j + 3; p++) {
        ans = (ans + dp[n - 2][p]) % mod;
      }
  }
  cout << ans << endl;
  return 0;
}