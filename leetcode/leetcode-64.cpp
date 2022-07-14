/*
 *@File Name          :leetcode-64.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/14 9:55
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (i || j) {
          int t = 100000;
          if (i) t = grid[i - 1][j];
          if (j) t = min(t, grid[i][j - 1]);
          grid[i][j] = t + grid[i][j];
        }
    }

    return grid[n - 1][m - 1];
  }
};
