/*
 *@File Name          :offer2-098.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 9:27
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (n > m) swap(n, m);
    long long t1 = 1, t2 = 1;
    for (int i = 1; i < n; i++) {
      t1 *= (n + m - i - 1);
      t2 *= i;
    }
    return t1 / t2;
  }
};