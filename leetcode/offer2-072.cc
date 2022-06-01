/*
 *@File Name          :offer2-072.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/1 8:22
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    if (x < 2) return x;
    int l = 1, r = x;
    int ans = 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (mid <= x / mid) {
        l   = mid + 1;
        ans = mid;
      } else
        r = mid - 1;
    }
    return ans;
  }
};