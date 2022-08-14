/*
 *@File Name          :meituan-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/6 10:25
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < n; j++) cin >> b[j];
  map<int, int> ma;
  map<int, int> mb;
  for (int i = 0; i < n; i++) { ma[b[i]]++; }
  for (int i = 0; i < n; i++) { mb[a[i]]++; }

  int k   = (n + 1) / 2;
  int ans = INT_MAX;
  for (auto& m : mb) {
    int x = m.first;
    int y = m.second;
    if (ma[x] >= k - y) { ans = min(ans, max(k - y, 0)); }
  }
  for (auto& m : ma) {
    if (m.second >= k) ans = k;
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << endl;
}