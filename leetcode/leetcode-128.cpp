/*
 *@File Name          :leetcode-128.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/22 9:51
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "climits"
#include "map"
#include "set"
#include "vector"
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    set<int> se(nums.begin(), nums.end());
    int      ans = 0;
    for (auto& x : se) {
      if (se.count(x - 1) == 0) {
        int t   = x;
        int cnt = 1;
        while (se.count(t + 1) == 1) {
          t++;
          cnt++;
        }
        ans = max(ans, cnt);
      }
    }
    return ans;
  }
};

//class Solution {
// public:
//  int longestConsecutive(vector<int>& nums) {
//    int n = nums.size();
//    map<int, int> dp;
//    int ans = 0;
//    for(auto &x: nums){
//      if(dp[x])
//        continue ;
//      dp[x] = 1;
//      int l = dp[x-1];
//      int r = dp[x+1];
//      dp[x-l] = l + r + 1;
//      dp[x+r] = l + r + 1;
//      ans = max(ans, l+r+1);
//    }
//    return ans;
//  }
//};