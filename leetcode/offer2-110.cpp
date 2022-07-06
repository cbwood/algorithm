/*
 *@File Name          :offer2-110.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 20:05
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<vector<int>> ans;

  void dfs(vector<vector<int>> graph, int cur, vector<int>& t) {
    if (cur == graph.size() - 1) {
      ans.push_back(t);
      return;
    }
    for (auto& x : graph[cur]) {
      t.push_back(x);
      dfs(graph, x, t);
      t.pop_back();
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> t;
    t.push_back(0);
    dfs(graph, 0, t);
    return ans;
  }
};