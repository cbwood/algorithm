/*
 *@File Name          :leetcode-560-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/14 20:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "map"
#include "vector"
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    map<int, int> ma;
    int           sumx = 0;
    ma[0]              = 1;
    int ans            = 0;
    for (auto& x : nums) {
      sumx += x;
      ma[sumx]++;
      ans += ma[sumx - k];
    }
    return ans;
  }
};