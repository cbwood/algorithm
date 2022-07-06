/*
 *@File Name          :offer2-115.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/6 14:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "queue"
#include "set"
#include "vector"
using namespace std;

class Solution {
 public:
  bool sequenceReconstruction(vector<int>&         nums,
                              vector<vector<int>>& sequences) {
    int n = nums.size();

    vector<set<int>> e(n + 1);
    vector<int>      d(n + 1, 0);

    for (auto& x : sequences) {
      int m = x.size();
      for (int i = 0; i < m - 1; i++) {
        e[x[i]].insert(x[i + 1]);
        d[x[i + 1]]++;
      }
    }
    queue<int> que;
    for (int i = 1; i <= n; i++)
      if (d[i] == 0) que.push(i);
    if (que.size() > 1) return false;

    while (!que.empty()) {
      int t = que.front();
      que.pop();
      for (auto& x : e[t]) {
        if (--d[x] == 0) { que.push(x); }
      }
      if (que.size() > 1) return false;
    }
    return true;
  }
};