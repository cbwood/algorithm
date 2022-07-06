/*
 *@File Name          :offer2-106.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 10:56
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "set"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<set<int>> ses;
  vector<bool>     vis;

  void dfs(vector<vector<int>>& graph, int cur, int dp) {
    ses[dp & 1].insert(cur);
    vis[cur] = true;
    for (auto& x : graph[cur]) {
      if (!vis[x]) { dfs(graph, x, dp + 1); }
    }
  }

  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    ses.resize(2, set<int>{});
    vis.resize(n, false);
    for (int i = 0; i < n; i++)
      if (!vis[i]) dfs(graph, i, 0);

    for (int i = 0; i < n; i++) {
      for (auto& x : graph[i]) {
        if ((ses[0].count(i) && ses[0].count(x)) ||
            (ses[1].count(i) && ses[1].count(x)))
          return false;
      }
    }
    return true;
  }
};