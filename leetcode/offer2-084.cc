/*
 *@File Name          :offer2-084.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/30 9:05
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<vector<int>> ans;
  vector<bool>        vis;

  void dfs(vector<int>& nums, vector<int>& t, int k) {
    if (k == nums.size()) {
      ans.push_back(t);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) continue;
      vis[i] = true;
      t.push_back(nums[i]);
      dfs(nums, t, k + 1);
      t.pop_back();
      vis[i] = false;
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vis.resize(10);
    std::sort(nums.begin(), nums.end());
    vector<int> t;
    dfs(nums, t, 0);
    return ans;
  }
};