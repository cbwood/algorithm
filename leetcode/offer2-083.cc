/*
 *@File Name          :offer2-083.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/30 8:47
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
      if (!vis[i]) {
        vis[i] = true;
        t.push_back(nums[i]);
        dfs(nums, t, k + 1);
        t.pop_back();
        vis[i] = false;
      }
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vis.resize(10, false);
    vector<int> t;
    dfs(nums, t, 0);
    return ans;
  }
};