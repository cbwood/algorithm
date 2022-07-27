/*
 *@File Name          :leetcode-153.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/27 9:03
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] < nums[r])
        r = mid;
      else
        l = mid + 1;
    }
    return nums[l];
  }
};