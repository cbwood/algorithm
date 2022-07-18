/*
 *@File Name          :leetcode-w302-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/17 11:32
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int k   = 1;
    int ans = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        k++;
      } else {
        ans += k / 2;
        k = 1;
      }
    }
    ans += k / 2;
    return {ans, (int)nums.size() - ans * 2};
  }
};