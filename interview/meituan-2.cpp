/*
 *@File Name          :meituan-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/6 10:08
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  vector<int> sumx(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (a[n - 1] <= 0) sumx[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    sumx[i] = sumx[i + 1];
    if (a[i] <= 0) sumx[i] += 1;
  }

  int prex = 0;
  if (a[0] >= 0) prex = 1;
  int ans = sumx[0];
  for (int i = 1; i < n - 1; i++) {
    ans = min(ans, prex + sumx[i]);
    if (a[i] >= 0) prex++;
  }
  ans = min(ans, prex);
  cout << ans << endl;
  return 0;
}