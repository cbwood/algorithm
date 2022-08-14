/*
 *@File Name          :leetcode-w306-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/14 10:52
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int                 n = grid.size();
    vector<vector<int>> a(n - 2, vector<int>(n - 2, 0));
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        int k = INT_MIN;
        for (int l = i - 1; l <= i + 1; l++) {
          for (int ll = j - 1; ll <= j + 1; ll++) k = max(k, grid[l][ll]);
        }
        a[i - 1][j - 1] = k;
      }
    }
    return a;
  }
};