/*
 *@File Name          :leetcode-283.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/1 9:20
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int l = 0, r = 1;
    int n = nums.size();
    while (l < n && nums[l] == 0) l++;
    r = l + 1;
    while (r < n) {
      if (nums[r]) swap(nums[r], nums[l++]);
      r++;
    }
    return;
  }
};