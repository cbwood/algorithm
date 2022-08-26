/*
 *@File Name          :bytedance-7.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/21 19:05
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    int t   = s[0] - '0';
    int l = s.size() - 1, r = s.size() - 1;
    int r1 = s.size() - 1, r0 = s.size() - 1;
    for (int i = s.size() - 1; i >= 0 && k > 0; i--) {
      if ((i - s.size()) & 1) {
        if (s[i] == '0') {
          r1 = i;
          while (r1 >= 0 && s[r1] != '1') r1--;
          k -= i - r1;
          if (r1 >= 0) swap(s[r1], s[i]);
        }
      } else {
        if (s[i] == '1') {
          r1 = i;
          while (r1 >= 0 && s[r1] != '0') r1--;
          k -= i - r1;
          if (r1 >= 0) swap(s[r1], s[i]);
        }
      }
    }
    for (int i = 1; i < s.size(); i++) {
      t = t * 10 + s[i] - '0';
      ans += t;
      t = t % 10;
    }
    cout << ans << endl;
  }
  return 0;
}