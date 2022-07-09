/*
 *@File Name          :leetcode-zj-future2022-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/8 10:41
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 7;

int s[N];

struct node {
  int x, y, sumx, sumy;
  int flag;
} a[N];

bool cmp1(node a, node b) { return a.x < b.x; }
bool cmp2(node a, node b) { return a.y < b.y; }

class Solution {
 public:
  int buildTransferStation(vector<vector<int>>& area) {
    int n = area.size();
    int m = area[0].size();

    vector<vector<pair<int, int>>> v(n + 1, vector<pair<int, int>>(m, {0, 0}));
    vector<int>                    sumy(n + 1, 0);
    vector<int>                    sumyy(n + 1, 0);
    vector<int>                    sumx(m + 1, 0);
    vector<int>                    sumxx(m + 1, 0);
    int                            nums = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (area[i][j] == 1) {
          sumy[i] += i;
          sumyy[i] += 1;
        }
      }
      if (i) {
        sumy[i] += sumy[i - 1];
        sumyy[i] += sumyy[i - 1];
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (area[j][i] == 1) {
          sumx[i] += i;
          sumxx[i]++;
        }
      }
      if (i) {
        sumx[i] += sumx[i - 1];
        sumxx[i] += sumxx[i - 1];
      }
    }

    vector<int> y(n + 1, 0);
    int         minx = INT_MAX;
    for (int i = 0; i < n; i++) {
      y[i] += sumy[n - 1] - sumy[i] - i * (sumyy[n - 1] - sumyy[i]);
      if (i > 0) { y[i] += i * sumyy[i - 1] - sumy[i - 1]; }
      minx = min(minx, y[i]);
    }
    vector<int> x(m + 1, 0);
    int         miny = INT_MAX;

    for (int j = 0; j < m; j++) {
      x[j] = sumx[m - 1] - sumx[j] - j * (sumxx[m - 1] - sumxx[j]);
      if (j > 0) { x[j] += j * sumxx[j - 1] - sumx[j - 1]; }
      miny = min(miny, x[j]);
    }
    return minx + miny;
  }
};