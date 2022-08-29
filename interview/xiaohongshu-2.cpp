/*
*@File Name          :xiaohongshu-2.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/28 16:28
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  std::sort(a.begin(), a.end());
  // a.push_back(INT_MAX);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int t = lower_bound(a.begin(), a.end(), (k + a[i] - 1) / a[i]) - a.begin();
    t     = max(i + 1, t);
    ans += (n - t) * 2;
  }
  cout << ans << endl;
  return 0;
}