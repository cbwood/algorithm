/*
 *@File Name          :ubiquant2022-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/21 17:35
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int  n, m;
  void dfs(int x, int y, vector<string>& field) {
    field[x][y] = '.';
    int dx[]    = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[]    = {1, -1, 0, 0, 1, -1, -1, 1};
    for (int i = 0; i < 8; i++) {
      int sx = x + dx[i];
      int sy = y + dy[i];
      if (sx >= 0 && sy >= 0 && sx < n && sy < m && field[sx][sy] == 'W') {
        dfs(sx, sy, field);
      }
    }
  }
  int lakeCount(vector<string>& field) {
    n = field.size();
    if (n == 0) return 0;
    m       = field[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (field[i][j] == 'W') {
          ans++;
          dfs(i, j, field);
        }
      }
    }
    return ans;
  }
};