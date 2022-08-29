/*
 *@File Name          :haoweilai-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/27 19:18
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> ans;

void dfs(int n, int k, int cur, vector<int>& q) {
  if (cur == n + 1) {
    if (k == q.size()) ans.push_back(q);
    return;
  }
  dfs(n, k, cur + 1, q);
  q.push_back(cur);
  dfs(n, k, cur + 1, q);
  q.pop_back();
}

int main() {
  int  n, k;
  char a;
  cin >> a >> a >> n >> a >> a >> a >> k;
  string      t;
  vector<int> q;
  dfs(n, k, 1, q);
  t.push_back('[');
  std::reverse(ans.begin(), ans.end());

  for (auto& x : ans) {
    t.push_back('[');
    for (auto& y : x) {
      t += to_string(y);
      t.push_back(',');
    }
    t.pop_back();
    t.push_back(']');
    t.push_back(',');
  }
  t.push_back(']');
  cout << t << endl;
  return 0;
}