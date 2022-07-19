/*
 *@File Name          :leetcode-34.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/19 10:06
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int serachL(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    if (r < 0) return -1;

    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] >= target)
        r = mid;
      else
        l = mid + 1;
    }
    return nums[l] == target ? l : -1;
  }

  int serachR(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    if (r < 0) return -1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (nums[mid] <= target)
        l = mid;
      else
        r = mid - 1;
    }
    return nums[l] == target ? l : -1;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    return {serachL(nums, target), serachR(nums, target)};
  }
};