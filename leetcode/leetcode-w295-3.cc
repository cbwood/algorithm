/*
 *@File Name          :leetcode-w295-3.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/29 10:21
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int minimumObstacles(vector<vector<int>>& grid) {
    priority_queue<pair<int, pair<int, int>>, deque<pair<int, pair<int, int>>>,
                   greater<>>
                         que;
    int                  n = grid.size();
    int                  m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    que.push({grid[0][0], {0, 0}});
    vis[0][0] = true;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    while (!que.empty()) {
      auto p = que.top();
      que.pop();
      int st = p.first;
      int x  = p.second.first;
      int y  = p.second.second;
      for (int i = 0; i < 4; i++) {
        int sx = x + dx[i];
        int sy = y + dy[i];
        if (sx >= 0 && sy >= 0 && sx < n && sy < m && !vis[sx][sy]) {
          vis[sx][sy] = true;
          que.push({st + grid[sx][sy], {sx, sy}});
          if (sx == n - 1 && sy == m - 1) return st + grid[sx][sy];
        }
      }
    }
    return n + m - 1;
  }
};