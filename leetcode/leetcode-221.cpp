/*
 *@File Name          :leetcode-221.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/19 10:31
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int                 ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') {
          if (i == 0 || j == 0)
            dp[i][j] = 1;
          else
            dp[i][j] =
                min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }
        ans = max(ans, dp[i][j] * dp[i][j]);
      }
    }

    return ans;
  }
};