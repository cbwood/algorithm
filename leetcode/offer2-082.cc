/*
 *@File Name          :offer2-082.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/13 8:29
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

  int getNext(vector<int>& candidates, int cur) {
    cur++;
    while (cur < candidates.size() && candidates[cur] == candidates[cur - 1]) cur++;
    return cur;
  }

  void dfs(vector<int>& candidates, int target, int sum, int cur, vector<int>& cand) {
    if (target == sum) {
      ans.push_back(cand);
      return;
    }
    if (cur >= candidates.size() || target < sum) return;
    dfs(candidates, target, sum, getNext(candidates, cur), cand);
    cand.push_back(candidates[cur]);
    dfs(candidates, target, sum + candidates[cur], cur + 1, cand);
    cand.pop_back();
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> t;
    std::sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, 0, t);
    return ans;
  }
};