/*
 *@File Name          :offer2-118.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/6 15:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
using namespace std;

class Solution {
 public:
  vector<int> f;

  void init(int n) {
    for (int i = 0; i < n; i++) f[i] = i;
  }

  int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
  }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    f[x] = y;
    return true;
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    f.resize(n + 1, 0);
    init(n + 1);

    for (auto& x : edges) {
      if (!merge(x[0], x[1])) return x;
    }
    return {};
  }
};