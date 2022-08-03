/*
 *@File Name          :leetcode-w304-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/31 11:07
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) {
        ans++;
        for (int j = i + 1; j < n; j++) { nums[j] -= nums[i]; }
      }
    }
    return ans;
  }
};