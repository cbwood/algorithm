/*
 *@File Name          :leetcode-w300-4.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/3 10:31
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  vector<vector<int>>  dp;
  vector<vector<bool>> vis;

  int n, m;
  int mod;

  int dfs(int sx, int sy, vector<vector<int>>& grid) {
    if (dp[sx][sy] != -1) return dp[sx][sy];
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    dp[sx][sy] = 1;
    for (int i = 0; i < 4; i++) {
      int tx = sx + dx[i];
      int ty = sy + dy[i];
      if (tx >= 0 && ty >= 0 && tx < n && ty < m && grid[sx][sy] < grid[tx][ty] && !vis[tx][ty]) {
        vis[tx][ty] = true;
        (dp[sx][sy] += dfs(tx, ty, grid)) %= mod;
        vis[tx][ty] = false;
      }
    }
    return dp[sx][sy];
  }

  int countPaths(vector<vector<int>>& grid) {
    mod = 1e9 + 7;
    n   = grid.size();
    m   = grid[0].size();
    dp.resize(n, vector<int>(m, -1));
    vis.resize(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        vis[i][j] = true;
        (ans += dfs(i, j, grid)) %= mod;
        vis[i][j] = false;
      }
    return ans;
  }
};