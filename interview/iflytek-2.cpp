/*
 *@File Name          :iflytek-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/23 19:49
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

inline long long dist(const pair<int, int>& p, const pair<int, int>& q) {
  return (p.first - q.first) * (p.first - q.first) +
         (p.second - q.second) * (p.second - q.second);
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) { cin >> a[i].first >> a[i].second; }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        long a1 = dist(a[i], a[j]);
        long a2 = dist(a[j], a[k]);
        long a3 = dist(a[k], a[i]);
        if (a1 + a2 == a3 || a1 + a3 == a2 || a2 + a3 == a1) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}