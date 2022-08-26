/*
 *@File Name          :legou-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/20 20:50
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 抵达铁门时可能的最大生命值，如果不可达，则返回 -1。
     * @param cave int整型vector<vector<>> 洞穴的信息
     * @param hp int整型 小明的初始生命值
     * @return int整型
     */
  int EscapeFromCave(vector<vector<int>>& cave, int hp) {
    // write code here
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    int n = cave.size();
    int m = cave[0].size();
    int xx, yy, ex, ey;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (cave[i][j] == -2) {
          xx = i;
          yy = j;
        } else if (cave[i][j] == -3) {
          ex = i;
          ey = j;
        }
      }
    }
    priority_queue<pair<int, pair<int, int>>> que;
    que.push({hp, {xx, yy}});
    while (!que.empty()) {
      auto t = que.top();
      que.pop();
      if (cave[t.second.first][t.second.second]) return t.first;
      cave[t.second.first][t.second.second] = -1;
      for (int i = 0; i < 4; i++) {
        int sx = t.second.first + dx[i];
        int sy = t.second.second + dy[i];
        if (sx >= 0 && sy >= 0 && sx < n && sy < m && cave[sx][sy] != -1) {
          int thp = t.first;
          if (cave[sx][sy] > 0) thp -= cave[sx][sy];
          if (thp > 0) { que.push({thp, {sx, sy}}); }
        }
      }
    }
    return -1;
  }
};
