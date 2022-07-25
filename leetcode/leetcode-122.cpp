/*
 *@File Name          :leetcode-122.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/25 9:12
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
      ans += max(0, prices[i + 1] - prices[i]);
    }
    return ans;
  }
};