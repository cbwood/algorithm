/*
 *@File Name          :leetcode-209.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/1 9:30
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "climits"
#include "vector"
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int sumx = 0;
    int ans  = INT_MAX;
    int n    = nums.size();
    int l = 0, r = 0;
    while (r < n) {
      sumx += nums[r];
      r++;
      while (l < r && sumx >= target) {
        ans = min(ans, r - l);
        sumx -= nums[l];
        l++;
      }
    }
    if (ans == INT_MAX) ans = 0;
    return ans;
  }
};