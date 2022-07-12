/*
 *@File Name          :leetcode-470.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/12 10:50
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
 public:
  int rand10() {
    int ans;
    do {
      int l = rand7();
      int t = rand7();
      ans   = l + (t - 1) * 7;
    } while (ans > 40);
    return 1 + (ans - 1) % 10;
  }
};