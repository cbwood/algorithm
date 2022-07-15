/*
 *@File Name          :leetcode-169.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/15 9:48
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int cnt = 0;
    int pre = 0;
    for (auto& x : nums) {
      if (cnt == 0) {
        cnt = 1;
        pre = x;
      } else if (pre != x) {
        cnt--;
      } else if (pre == x)
        cnt++;
    }
    return pre;
  }
};