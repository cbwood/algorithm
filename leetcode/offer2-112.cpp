/*
 *@File Name          :offer2-112.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 20:50
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<vector<int>> dp;

  int n, m;
  int ans = 0;

  int dfs(vector<vector<int>>& matrix, int sx, int sy) {
    if (dp[sx][sy] != -1) return dp[sx][sy];
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    int t = 1;
    for (int i = 0; i < 4; i++) {
      int tx = sx + dx[i];
      int ty = sy + dy[i];
      if (tx >= 0 && ty >= 0 && tx < n && ty < m &&
          matrix[tx][ty] > matrix[sx][sy]) {
        t = max(dfs(matrix, tx, ty) + 1, t);
      }
    }
    return dp[sx][sy] = t;
  }

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix[0].size();

    dp.resize(n, vector<int>(m, -1));

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) { ans = max(ans, dfs(matrix, i, j)); }
    }
    return ans;
  }
};