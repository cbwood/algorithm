/*
 *@File Name          :offer2-094.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/4 18:52
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "climits"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<vector<int>> dp;
  vector<int>         cnt;

  int n;

  int dfs(int pre) {
    if (pre == n) { return 0; }
    if (cnt[pre] != -1) return cnt[pre];
    int tmp = INT_MAX;
    for (int j = pre; j < n; j++) {
      if (dp[pre][j]) tmp = min(dfs(j + 1) + 1, tmp);
    }
    return cnt[pre] = tmp;
  }

  int minCut(string s) {
    n = s.size();
    dp.resize(n, vector<int>(n, 0));
    cnt.resize(n, -1);
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
      if (i < n - 1 && s[i] == s[i + 1]) dp[i][i + 1] = 1;
    }

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 2; j < n; j++) {
        if (s[i] == s[j]) dp[i][j] |= dp[i + 1][j - 1];
      }
    }

    return dfs(0) - 1;
  }
};