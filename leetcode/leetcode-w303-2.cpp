/*
 *@File Name          :leetcode-w303-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/24 10:18
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    int n   = grid.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        bool check = true;

        for (int k = 0; k < n && check; k++) {
          if (grid[i][k] != grid[k][j]) check = false;
        }
        if (check) ans++;
      }
    }
    return ans;
  }
};