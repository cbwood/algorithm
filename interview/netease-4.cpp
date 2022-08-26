/*
 *@File Name          :netease-4.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/20 15:24
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
  long long ans   = 0;
  int       minx1 = INT_MIN;
  for (int i = 0; i < n; i += 2) { minx1 = max(minx1, a[i]); }
  for (int i = 0; i < n; i += 2) { ans += minx1 - a[i]; }

  int minx2 = INT_MIN;
  for (int i = 1; i < n; i += 2) { minx2 = max(minx2, a[i]); }
  for (int i = 1; i < n; i += 2) { ans += minx2 - a[i]; }

  if (minx1 == minx2) { ans += n / 2; }
  cout << ans << endl;
  return 0;
}