/*
 *@File Name          :leetcode-912-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/26 9:32
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  void push_down(int i, int n, vector<int>& nums) {
    while (i < n) {
      int t = 2 * i + 1;
      if (t + 1 < n && nums[t + 1] > nums[t]) t++;
      if (t >= n) return;
      if (nums[i] >= nums[t]) return;
      swap(nums[i], nums[t]);
      i = t;
    }
  }

  vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    for (int i = n / 2; i >= 0; --i) push_down(i, n, nums);
    for (int i = n - 1; i >= 0; --i) {
      swap(nums[i], nums[0]);
      push_down(0, i, nums);
    }
    return nums;
  }
};