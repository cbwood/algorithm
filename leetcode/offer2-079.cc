/*
 *@File Name          :offer2-079.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/8 8:44
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  void dfs(vector<vector<int>>& ans, int cur, vector<int>& nums,
           vector<int>& t) {
    if (cur == nums.size()) {
      ans.push_back(t);
      return;
    }
    dfs(ans, cur + 1, nums, t);
    t.push_back(nums[cur]);
    dfs(ans, cur + 1, nums, t);
    t.pop_back();
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int>         t;
    dfs(ans, 0, nums, t);
    return ans;
  }
};