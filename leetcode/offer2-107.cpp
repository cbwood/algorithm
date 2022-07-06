/*
 *@File Name          :offer2-107.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 15:12
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
  vector<vector<bool>> vis;

  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    auto ans = mat;
    int  n   = mat.size();
    int  m   = mat[0].size();
    vis.resize(n, vector<bool>(m, false));

    queue<pair<int, int>> que;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 0) {
          vis[i][j] = true;
          que.push({i, j});
        }
      }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!que.empty()) {
      auto q = que.front();
      que.pop();
      for (int i = 0; i < 4; i++) {
        int sx = q.first + dx[i];
        int sy = q.second + dy[i];
        if (sx >= 0 && sy >= 0 && sx < n && sy < m && !vis[sx][sy]) {
          ans[sx][sy] = ans[q.first][q.second] + 1;
          que.push({sx, sy});
          vis[sx][sy] = true;
        }
      }
    }
    return ans;
  }
};