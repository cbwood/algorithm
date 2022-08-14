/*
 *@File Name          :leetcode-w306-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/14 10:56
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  bool              vis[100005];
  vector<long long> ans;

  void dfs(int cur, vector<int>& e, int pre) {
    ans[cur] += pre;
    if (!vis[cur]) {
      vis[cur] = true;

      dfs(e[cur], e, cur);
    }
  }

  int edgeScore(vector<int>& edges) {
    memset(vis, false, sizeof vis);
    int n = edges.size();
    ans.resize(n, 0);
    long long maxi = INT_MIN;
    int       as   = 0;
    for (int i = 0; i < n; i++) { dfs(i, edges, 0); }
    for (int i = 0; i < n; i++) {
      if (maxi < ans[i]) {
        as   = i;
        maxi = ans[i];
      }
    }
    return as;
  }
};