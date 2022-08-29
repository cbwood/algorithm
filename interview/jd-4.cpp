/*
*@File Name          :jd-4.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/27 20:14
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

const long long mod = 1e9 + 7;

long long qpow(long long x, int n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  if (n < 6) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 6) {
    cout << 1 << endl;
    return 0;
  }
  n -= 6;
  long long ans = qpow(26, n);
  ans           = ans * (n + 1) % mod * (n + 2) % mod * qpow(2, mod - 2) % mod;
  //   ans = ans *( 1LL*(n+1)*n/2 +n+1) % mod;
  cout << ans % mod << endl;
  return 0;
}