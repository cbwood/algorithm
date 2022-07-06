/*
 *@File Name          :offer2-105.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 10:27
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  int ans = 0;

  void dfs(int sx, int sy, vector<vector<int>>& grid) {
    ans++;
    grid[sx][sy]    = 0;
    static int dx[] = {0, 0, 1, -1};
    static int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
      int tx = sx + dx[i];
      int ty = sy + dy[i];
      if (tx >= 0 && ty >= 0 && tx < grid.size() && ty < grid[0].size() &&
          grid[tx][ty] == 1) {
        dfs(tx, ty, grid);
      }
    }
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int tans = 0;
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        if (grid[i][j] == 1) {
          ans = 0;
          dfs(i, j, grid);
          tans = max(tans, ans);
        }
    return tans;
  }
};