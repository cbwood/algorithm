/*
 *@File Name          :360-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/27 15:11
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int                 ans = 0;
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) { cin >> a[i][j]; }
  }
  vector<int> dp(m, 0);
  vector<int> tt(n, 0);
  int         sumx = 0;
  for (int i = 0; i < n; i++) {
    int tmp = 0;
    for (int j = 0; j < m; j++) {
      dp[j] += a[i][j];
      if (i >= 7) dp[j] -= a[i - 7][j];
      tmp = max(tmp, dp[j]);
    }
    if (i >= 7) { sumx -= tt[i - 7]; }
    tt[i] = max(0, tmp - sumx + 1);
    ans += tt[i];
    sumx += tt[i];
  }
  cout << ans << endl;
  return 0;
}