/*
 *@File Name          :leetcode-33-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/27 9:37
 *@Description        :将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。此时有序部分用二分法查找。无序部分再一分为二，其
 *                     中一个一定有序，另一个可能有序，可能无序。就这样循环.
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) return mid;

      if (nums[l] <= nums[mid]) {
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
    return -1;
  }
};