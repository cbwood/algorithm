/*
 *@File Name          :leetcode-162.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/20 10:10
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "climits"
#include "vector"
using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    auto get = [&](int x) {
      if (x < 0) return INT_MIN;
      if (x >= n) return INT_MAX;
      return nums[x];
    };

    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1)) return mid;
      if (get(mid) < get(mid + 1))
        l = mid + 1;
      else
        r = mid - 1;
    }
    return -1;
  }
};