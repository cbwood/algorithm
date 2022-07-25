/*
 *@File Name          :leetcode-695.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/25 9:41
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "queue"
#include "vector"
using namespace std;

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int ans  = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (grid[i][j] == 1) {
          queue<pair<int, int>> que;
          grid[i][j] = 0;
          que.push({i, j});
          int k = 0;
          while (!que.empty()) {
            k++;
            auto t = que.front();
            que.pop();
            for (int l = 0; l < 4; l++) {
              int tx = dx[l] + t.first;
              int ty = dy[l] + t.second;
              if (tx >= 0 && ty >= 0 && tx < n && ty < m && grid[tx][ty] == 1) {
                grid[tx][ty] = 0;
                que.push({tx, ty});
              }
            }
          }
          ans = max(ans, k);
        }
    }
    return ans;
  }
};