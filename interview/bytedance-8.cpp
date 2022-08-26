/*
*@File Name          :bytedance-8.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/21 19:10
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;
int                  n, m;
vector<string>       a;
vector<vector<bool>> vis;
vector<vector<int>>  dp;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

map<char, int> ma;

int dfs(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];
  if (a[x][y] == 'O') return dp[x][y] = 1;

  if (vis[x][y] && a[x][y] != '.') return dp[x][y] = 0;
  vis[x][y] = true;

  if (a[x][y] != '.') {
    int sx = x + dx[ma[a[x][y]]];
    int sy = y + dy[ma[a[x][y]]];
    if (sx < 0 || sy < 0 || sx >= n || sy >= m) return dp[x][y] = 0;
    dp[x][y] = dfs(sx, sy);
    return dp[x][y];
  }
  int k = 0;
  for (int i = 0; i < 4; i++) {
    int sx = x + dx[i];
    int sy = y + dy[i];
    if (sx >= 0 && sy >= 0 && sx < n && sy < m) {
      if (a[sx][sy] == '.' && !vis[sx][sy]) k += dfs(sx, sy);

      if (a[sx][sy] != '.') k += dfs(sx, sy);
    }
  }
  vis[x][y] = false;
  if (k == 0)
    dp[x][y] = 0;
  else
    dp[x][y] = 1;
  return dp[x][y];
}

int dfs1(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];
  if (a[x][y] == 'O') return dp[x][y] = 1;

  if (vis[x][y]) return dp[x][y] = 0;

  vis[x][y] = true;

  if (a[x][y] == '.') {
    vis[x][y] = false;
    return -1;
  }

  int sx = x + dx[ma[a[x][y]]];
  int sy = y + dy[ma[a[x][y]]];

  if (sx < 0 || sy < 0 || sx >= n || sy >= m) { return dp[x][y] = 0; }
  dp[x][y] = dfs(sx, sy);

  return dp[x][y];
}

int main() {
  cin >> n >> m;
  ma['L'] = 1;
  ma['R'] = 0;
  ma['D'] = 2;
  ma['U'] = 3;
  a.resize(n);
  for (int i = 0; i < n; i++) { cin >> a[i]; }
  vis.resize(n, vector<bool>(m, false));
  dp.resize(n, vector<int>(m, -1));

  int tx, ty;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'O') {
        tx = i;
        ty = j;
      }
    }
  }
  queue<pair<int, int>> que;
  que.push({tx, ty});
  vis[tx][ty] = true;
  dp[tx][ty]  = 1;
  while (!que.empty()) {
    auto t = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int sx = t.first + dx[i];
      int sy = t.second + dy[i];
      if (sx >= 0 && sy >= 0 && sx < n && sy < m && !vis[sx][sy] &&
          a[sx][sy] == '.') {
        vis[sx][sy] = true;
        dp[sx][sy]  = 1;
        que.push({sx, sy});
      }
    }
  }

  //  for (int i = 0; i < n; i++) {
  //    for (int j = 0; j < m; j++) { dfs1(i, j); }
  //  }
  //  vis.resize(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) { dfs(i, j); }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j] == 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}