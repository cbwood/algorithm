/*
 *@File Name          :meituan-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/6 9:54
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

bool check(long long mid, int x, int y) {
  x -= mid;
  y -= mid;
  return (x + y) >= mid;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    long long l = 0, r = x;
    long long ans = 0;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (check(mid, x, y)) {
        ans = mid;
        l   = mid + 1;
      } else
        r = mid - 1;
    }
    cout << ans << endl;
  }
  return 0;
}