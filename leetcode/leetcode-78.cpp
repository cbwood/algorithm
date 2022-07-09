/*
 *@File Name          :leetcode-78.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/8 9:57
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

  void dfs(vector<int>& nums, int cur, vector<int>& t) {
    if (cur == nums.size()) {
      ans.push_back(t);
      return;
    }
    dfs(nums, cur + 1, t);
    t.push_back(nums[cur]);
    dfs(nums, cur + 1, t);
    t.pop_back();
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    vector<int> t;
    dfs(nums, 0, t);
    return ans;
  }
};