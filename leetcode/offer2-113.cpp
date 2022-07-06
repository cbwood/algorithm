/*
 *@File Name          :offer.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/6 9:01
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  vector<int> ans;
  vector<int> vis;

  bool dfs(vector<vector<int>>& e, int cur) {
    vis[cur] = -1;
    for (auto& x : e[cur]) {
      if (vis[x] == -1)
        return false;
      else if (vis[x] == 0)
        if (!dfs(e, x)) return false;
    }
    vis[cur] = 1;
    ans.push_back(cur);
    return true;
  }

  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vis.resize(numCourses, 0);
    vector<vector<int>> e(numCourses);
    for (auto& x : prerequisites) { e[x[0]].push_back(x[1]); }
    for (int i = 0; i < numCourses; i++) {
      if (!vis[i])
        if (!dfs(e, i)) return {};
    }
    return ans;
  }
};