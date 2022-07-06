/*
 *@File Name          :offer2-116.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/6 14:47
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<int> f;
  int         ans;
  void        init_f(int n) {
           for (int i = 0; i < n; i++) f[i] = i;
  }

  int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) ans--;
    f[x] = y;
  }

  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    ans   = n;
    f.resize(n, 0);
    init_f(n);

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (isConnected[i][j]) merge(i, j);
    return ans;
  }
};