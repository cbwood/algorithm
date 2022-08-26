/*
*@File Name          :qianxin-2.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/25 19:43
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

int main() {
  string s;
  cin >> s;
  s = s.substr(1, s.size() - 2);
  vector<unsigned int> a;
  unsigned int         nums = 0;
  for (auto& x : s) {
    if (x == ',') {
      a.push_back(nums);
      nums = 0;
    } else
      nums = nums * 10 + x - '0';
  }
  a.push_back(nums);
  long long ans = 0;

  int l = 0, r = a.size() - 1;
  while (l < r) {
    long long t;
    if (a[r] > a[l]) {
      t = a[l];
      l++;
    } else
      t = a[r], r--;
    ans = max(ans, (r - l + 1) * t);
  }
  cout << ans << endl;
  return 0;
}