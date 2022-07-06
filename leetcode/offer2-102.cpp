/*
 *@File Name          :offer2-102.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 9:50
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  vector<int> sumx;
  int         n;
  int         ans = 0;

  void dfs(vector<int>& nums, int cur, int s, int target) {
    if (cur == n) {
      if (s == target) ans++;
      return;
    }
    if (s - sumx[cur] > target) return;
    if (s + sumx[cur] < target) return;
    dfs(nums, cur + 1, s + nums[cur], target);
    dfs(nums, cur + 1, s - nums[cur], target);
  }

  int findTargetSumWays(vector<int>& nums, int target) {
    n = nums.size();
    sumx.resize(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) { sumx[i] = sumx[i + 1] + nums[i]; }

    dfs(nums, 0, 0, target);
    return ans;
  }
};