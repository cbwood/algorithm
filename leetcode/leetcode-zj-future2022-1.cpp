/*
 *@File Name          :leetcode-zj-future2022-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/8 10:19
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  bool canReceiveAllSignals(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] < intervals[i - 1][1]) return false;
    }
    return true;
  }
};