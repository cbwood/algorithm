/*
 *@File Name          :offer2-088.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/4 10:40
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int a = 0, b = 0;
    for (int i = 2; i <= n; i++) {
      int c = min(a + cost[i - 2], b + cost[i - 1]);
      a     = b;
      b     = c;
    }
    return b;
  }
};