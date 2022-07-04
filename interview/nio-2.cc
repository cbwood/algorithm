/*
 *@File Name          :nio-2.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/1 19:26
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e3 + 10;
long long a[maxn], b[maxn], c[maxn];
long long dp[maxn][maxn];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) { cin >> a[i]; }
  for (int i = 0; i < n; i++) { cin >> b[i]; }
  for (int i = 0; i < n; i++) { cin >> c[i]; }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++) dp[i][j] = LONG_LONG_MIN / 2;
  dp[0][0] = a[0] + 1500;
  if (k >= c[0]) dp[0][c[0]] = 1500 + b[0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = dp[i - 1][j] + a[i];
      if (j >= c[i]) { dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + b[i]); }
    }
  }
  long long ans = LONG_LONG_MIN;
  for (int i = 0; i <= k; i++) ans = max(ans, dp[n - 1][i]);
  cout << ans << endl;
  return 0;
}