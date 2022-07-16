/*
 *@File Name          :leetcode-48.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/16 9:43
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 1) return;
    for (int i = 0; i < n / 2; i++) {
      for (int j = i; j < n - i - 1; j++) {
        int t                        = matrix[i][j];
        matrix[i][j]                 = matrix[n - j - 1][i];
        matrix[n - j - 1][i]         = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1]         = t;
      }
    }
  }
};