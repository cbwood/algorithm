/*
 *@File Name          :offer2-081.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/13 8:18
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  vector<vector<int>> ans;

  void dfs(vector<int>& candidates, int target, int cur, vector<int>& tmp, int i) {
    if (cur >= target) {
      if (cur == target) { ans.push_back(tmp); }
      return;
    }
    if (i >= candidates.size()) return;
    int k = 0;
    dfs(candidates, target, cur, tmp, i + 1);
    int tmpSum = cur;
    while (tmpSum + candidates[i] <= target) {
      tmpSum += candidates[i];
      tmp.push_back(candidates[i]);
      dfs(candidates, target, tmpSum, tmp, i + 1);
    }
    while (tmpSum > cur) {
      tmp.pop_back();
      tmpSum -= candidates[i];
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> t;
    dfs(candidates, target, 0, t, 0);
    return ans;
  }
};