/*
*@File Name          :netease-5.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/20 15:30
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"

using namespace std;

int solve(string& s, int l, int r) {
  if (r - l + 1 < 3) return 0;
  int            ans = 0;
  int            n   = s.size();
  map<int, char> ma;
  ma[0] = 'r';
  ma[1] = 'e';
  ma[2] = 'd';
  ma[3] = 'e';

  for (int i = 0; i + l < r; i++) {
    if (ma[i % 4] != s[i + l]) ans++;
  }

  int ans1 = 0;
  ma[0]    = 'd';
  ma[1]    = 'e';
  ma[2]    = 'r';
  ma[3]    = 'e';

  for (int i = 0; i + l < r; i++) {
    if (ma[i % 4] != s[i + l]) ans1++;
  }

  return min(ans, ans1);
}

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if (n < 3) {
    cout << 0 << endl;
    return 0;
  }
  if (n & 1) {
    cout << solve(s, 0, n) << endl;
  } else {
    int ans = INT_MAX;

    for (int i = 1; i < n; i += 2) {
      ans = min(ans, solve(s, 0, i) + solve(s, i, n));
    }
    cout << ans << endl;
  }

  return 0;
}