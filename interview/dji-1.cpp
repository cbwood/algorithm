/*
*@File Name          :dji-1.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/7 18:51
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"

using namespace std;

int main() {
  int n, m, x, y, d;
  cin >> n >> m >> x >> y >> d;

  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) { cin >> a[i][j]; }

  int dx[] = {0, 0, -1, 1};
  int dy[] = {1, -1, 0, 0};

  swap(x, y);
  queue<pair<int, int>> que;
  que.push({x, y});
  int ans = 0;
  int tmp = a[x][y];
  a[x][y] = -1;
  while (!que.empty()) {
    ans++;
    auto t = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int sx = t.first + dx[i];
      int sy = t.second + dy[i];
      if (sx >= 0 && sy >= 0 && sx < n && sy < m && abs(a[sx][sy] - tmp) < d &&
          a[sx][sy] != -1) {
        a[sx][sy] = -1;
        que.push({sx, sy});
      }
    }
  }
  cout << ans << endl;
  return 0;
}