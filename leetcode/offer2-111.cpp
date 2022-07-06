/*
 *@File Name          :offer2-111.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/5 20:22
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "map"
#include "queue"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>&         values,
                              vector<vector<string>>& queries) {
    vector<double>                            ans;
    map<string, vector<pair<string, double>>> e;

    for (int i = 0; i < equations.size(); i++) {
      e[equations[i][0]].push_back({equations[i][1], values[i]});
      e[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
    }

    for (auto& x : queries) {
      queue<pair<string, double>> que;
      que.push({x[0], 1});
      map<string, bool> vis;
      vis[x[0]] = true;
      ans.push_back(-1.0);
      if (e[x[0]].empty() || e[x[1]].empty()) continue;
      while (!que.empty()) {
        auto q = que.front();
        que.pop();
        if (q.first == x[1]) {
          ans.pop_back();
          ans.push_back(q.second);
          break;
        }
        for (auto& y : e[q.first]) {
          if (!vis[y.first]) {
            vis[y.first] = true;
            que.push({y.first, y.second * q.second});
          }
        }
      }
    }
    return ans;
  }
};