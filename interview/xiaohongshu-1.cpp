/*
 *@File Name          :xiaohongshu-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/28 16:16
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
  int n, m, id;
  cin >> n >> m >> id;
  vector<vector<int>> a(n, vector<int>(m, 0));

  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    int sumx = 0;
    for (int j = 0; j < m; j++) {
      int x = 0;
      cin >> x;
      sumx += x;
    }
    p.emplace_back(sumx, i + 1);
  }
  std::sort(p.begin(), p.end(), [](pair<int, int>& p, pair<int, int>& q) {
    if (p.first == q.first) return p.second < q.second;
    return p.first > q.first;
  });
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].second == id) {
      ans = i;
      break;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}