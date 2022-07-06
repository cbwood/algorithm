/*
 *@File Name          :offer2-100.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 9:37
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();

    for (int i = n - 2; i >= 0; --i)
      for (int j = 0; j <= i; j++) {
        triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
      }
    return triangle[0][0];
  }
};