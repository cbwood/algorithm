/*
 *@File Name          :leetcode-w300-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/3 10:59
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<int> dp(n + 10, 0);

    int mod = 1e9 + 7;
    dp[1]   = 1;

    for (int i = 2; i <= n; i++) {
      for (int j = 1; j < i; j++)
        if (i - j >= delay && i - j < forget) { dp[i] += dp[j]; }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    for (int i = max(n - forget, 1); i <= n; i++) ans += dp[i];
    return ans;
  }
};