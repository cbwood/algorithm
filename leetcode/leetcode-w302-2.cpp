/*
 *@File Name          :leetcode-w302-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/17 11:20
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    map<int, int> ma;
    int           ans = -1;
    int           k   = 0;
    for (auto& x : nums) {
      int t   = x;
      int tmp = 0;
      while (t) {
        tmp += t % 10;
        t /= 10;
      }
      if (ma.count(tmp)) { ans = max(ans, x + nums[ma[tmp]]); }

      if (!ma.count(tmp) || nums[ma[tmp]] < x) ma[tmp] = k;
      k++;
    }
    return ans;
  }
};