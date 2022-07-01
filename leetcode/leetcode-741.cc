/*
 *@File Name          :leetcode-741.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/13 8:59
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int dfs(vector<vector<vector<int>>>& dp, vector<vector<int>>& grid, int x1, int y1, int x2, int n, int m) {
    int y2 = x1 + y1 - x2;

    if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || x2 < 0 || y2 < 0 || x2 >= n || y2 >= m) return -1;
    if (dp[x1][y1][x2] != -2) return dp[x1][y1][x2];
    if (x1 == n - 1 && y1 == m - 1) return grid[x1][y1];
    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) return -1;

    int tmp = max(max(dfs(dp, grid, x1 + 1, y1, x2, n, m), dfs(dp, grid, x1 + 1, y1, x2 + 1, n, m)),
                  max(dfs(dp, grid, x1, y1 + 1, x2, n, m), dfs(dp, grid, x1, y1 + 1, x2 + 1, n, m)));
    if (tmp == -1) return dp[x1][y1][x2] = -1;

    tmp = max(tmp, 0) + grid[x1][y1];
    if (x1 != x2) tmp += grid[x2][y2];

    return dp[x1][y1][x2] = tmp;
  }

  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n, -2)));

    return max(dfs(dp, grid, 0, 0, 0, n, m), 0);
  }
};