/*
 *@File Name          :leetcode-240.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/21 9:36
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int l = n - 1, r = 0;

    while (l >= 0 && r < m) {
      if (matrix[l][r] > target)
        l--;
      else if (matrix[l][r] < target)
        r++;
      else
        return true;
    }
    return false;
  }
};
