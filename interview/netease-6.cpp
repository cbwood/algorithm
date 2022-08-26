/*
*@File Name          :netease-6.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/20 16:01
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int>           a(n);
  map<int, vector<int>> ma;
  map<int, int>         mb;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ma[a[i]].push_back(i);
  }
  for (auto& x : ma) { std::sort(x.second.begin(), x.second.end()); }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    auto t = ma.lower_bound(a[i]);
    t++;
    while (t != ma.end()) {
      if (i <= *t->second.begin() || i >= *t->second.rbegin()) {
        t++;
        continue;
      }
      int p = std::lower_bound(t->second.begin(), t->second.end(), i) -
              (t->second).begin();

      if (p && p < t->second.size()) ans += p * (t->second.size() - p);
      t++;
    }
  }
  cout << ans << endl;
  return 0;
}