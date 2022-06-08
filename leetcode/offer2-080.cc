/*
 *@File Name          :offer2-080.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/8 8:49
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  void dfs(vector<vector<int>>& ans, vector<int>& t, int cur, int n, int k) {
    if (k == 0) {
      ans.push_back(t);
      return;
    }
    if (cur == n) { return; }

    dfs(ans, t, cur + 1, n, k);
    t.push_back(cur + 1);
    dfs(ans, t, cur + 1, n, k - 1);
    t.pop_back();
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int>         t;
    dfs(ans, t, 0, n, k);
    return ans;
  }
};