/*
*@File Name          :leetcode-w301-4.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/7/10 10:32
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll          Mod = 1e9 + 7;
ll                fac[100010];  //存阶乘
ll                inv[100010];  //存逆元

ll quick(ll a, int b)  //快速幂算法
{
  ll ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % Mod;
    a = a * a % Mod;
    b >>= 1;
  }
  return ans;
}

void getfac() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    fac[i] = fac[i - 1] * i % Mod;
    inv[i] = quick(fac[i], Mod - 2);
  }
}

ll getans(ll n, ll m) { return fac[n] * inv[n - m] % Mod * inv[m] % Mod; }

class Solution {
 public:
  int  ans = 0;
  int  mod = 1e9 + 7;
  void dfs(int pre, int maxValue, int n, vector<int>& t) {
    if (t.size() > n) { return; }
    (ans += getans(n - 1, t.size() - 1)) %= mod;
    for (int i = pre * 2; i <= maxValue; i += pre) {
      t.push_back(i);
      dfs(i, maxValue, n, t);
      t.pop_back();
    }
  }

  int idealArrays(int n, int maxValue) {
    vector<int> t;
    getfac();
    for (int i = 1; i <= maxValue; i++) {
      t.push_back(i);
      dfs(i, maxValue, n, t);
      t.pop_back();
    }

    return ans;
  }
};