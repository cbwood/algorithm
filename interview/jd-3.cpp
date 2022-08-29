/*
*@File Name          :jd-3.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/27 20:01
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
  for (int i = 0; i < n; i++) { cin >> a[i]; }
  int                   ans = 0;
  vector<map<int, int>> ma(2);
  for (int i = 0; i < n; i++) { ma[i & 1][a[i]]++; }
  vector<pair<int, int>> v0, v1;
  for (auto& x : ma[0]) { v0.push_back({x.second, x.first}); }
  for (auto& x : ma[1]) { v1.push_back({x.second, x.first}); }
  std::sort(v0.begin(), v0.end(), greater<>());
  std::sort(v1.begin(), v1.end(), greater<>());

  if (v0[0].second != v1[0].second) {
    ans = n - v0[0].first - v1[0].first;
  } else {
    ans = n - max(v0[1].first + v1[0].first, v0[0].first + v1[1].first);
  }
  cout << ans << endl;
  return 0;
}