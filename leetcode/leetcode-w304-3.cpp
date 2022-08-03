/*
 *@File Name          :leetcode-w304-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/31 10:48
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  vector<vector<int>>  d;
  vector<vector<bool>> vis;
  void                 dfs(vector<int>& edges, int start, int dp, int k) {
    if (start == -1 || vis[k][start]) return;
    d[k][start]   = dp;
    vis[k][start] = true;
    dfs(edges, edges[start], dp + 1, k);
  }

  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    d.resize(2, vector<int>(n, -1));
    vis.resize(2, vector<bool>(n, false));

    dfs(edges, node1, 0, 0);

    dfs(edges, node2, 0, 1);

    int ans = INT_MAX;
    int k   = -1;
    for (int i = 0; i < n; i++) {
      if (d[0][i] != -1 && d[1][i] != -1) {
        if (ans > max(d[0][i], d[1][i])) {
          k   = i;
          ans = max(d[0][i], d[1][i]);
        }
      }
    }
    return k;
  }
};