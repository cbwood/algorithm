/*
 *@File Name          :leetcode-w302-4.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/17 10:31
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
  int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    std::sort(nums.begin(), nums.end());
    int g = numsDivide[0];
    for (auto& x : numsDivide) { g = gcd(g, x); }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < g) break;
      if (i && nums[i] == nums[i - 1]) continue;
      if (g % nums[i] == 0) return i;
    }
    return -1;
  }
};