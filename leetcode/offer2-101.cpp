/*
 *@File Name          :offer2-101.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 9:44
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sumx = 0;
    for (auto& x : nums) sumx += x;
    if (sumx & 1) return false;
    vector<int> dp(sumx / 2 + 1, 0);
    dp[0] = 1;
    for (auto& x : nums) {
      for (int j = sumx / 2; j >= x; --j) dp[j] |= dp[j - x];
    }
    return dp[sumx / 2];
  }
};