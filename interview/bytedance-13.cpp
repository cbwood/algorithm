/*
 *@File Name          :bytedance-13.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/28 11:16
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> dp(n, 0);
  dp[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) { dp[i] = max(dp[i + 1], 0) + a[i]; }
  int l   = a[0];
  int ls  = a[0];
  int ans = dp[0];
  for (int i = 1; i < n; i++) {
    ans = max(ans, ls + dp[i]);
    l   = max(l, 0) + a[i];
    ls  = max(ls, l);
  }
  cout << ans << endl;
  return 0;
}