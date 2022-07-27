/*
 *@File Name          :leetcode-81.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/27 10:14
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) return true;
      if (nums[l] == nums[r] && nums[l] == nums[mid]) {
        l++;
        r--;
      } else if (nums[l] <= nums[mid]) {
        if (nums[l] <= target && target < nums[mid])
          r = mid - 1;
        else
          l = mid + 1;
      } else {
        if (nums[mid] < target && target <= nums[r])
          l = mid + 1;
        else
          r = mid - 1;
      }
    }
    return false;
  }
};