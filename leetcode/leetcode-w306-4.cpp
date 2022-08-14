/*
 *@File Name          :leetcode-w306-4.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/14 10:30
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int a[100];
  int dp[50][2050];

  int dfs(int pos, int state, bool limit, bool lead, int n) {
    if (pos == -1) return n != 0;
    if (dp[pos][state] != -1 && !limit && !lead) return dp[pos][state];

    int up   = limit ? a[pos] : 9;
    int sumx = 0;
    for (int i = 0; i <= up; i++) {
      if (lead && i == 0) {
        sumx += dfs(pos - 1, state, i == a[pos] && limit, lead, n * 10 + i);
      } else if ((state & (1 << i)) == 0) {
        sumx += dfs(pos - 1, (state | (1 << i)), i == a[pos] && limit,
                    lead && i == 0, n * 10 + i);
      }
    }
    if (!limit && !lead) dp[pos][state] = sumx;
    return sumx;
  }

  int countSpecialNumbers(int n) {
    int pos = 0;
    while (n) {
      a[pos++] = n % 10;
      n /= 10;
    }
    memset(dp, -1, sizeof dp);
    return dfs(pos - 1, 0, true, true, 0);
  }
};