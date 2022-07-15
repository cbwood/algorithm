/*
 *@File Name          :leetcode-39.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/15 9:23
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

  void dfs(vector<int>& candidates, int target, vector<int>& t, int cur) {
    if (target == 0) {
      ans.push_back(t);
      return;
    }
    if (target < 0) return;
    if (cur == candidates.size()) return;

    for (int i = cur; i < candidates.size(); i++) {
      t.push_back(candidates[i]);
      dfs(candidates, target - candidates[i], t, i);
      t.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> t;
    dfs(candidates, target, t, 0);
    return ans;
  }
};