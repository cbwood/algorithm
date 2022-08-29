/*
*@File Name          :xiaohongshu-3.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/28 16:44
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

map<int, int>  match;
map<int, bool> vis;

bool dfs(map<int, vector<int>>& e, int cur) {
  for (auto& x : e[cur]) {
    if (vis.count(x) == 0) {
      vis[x] = true;
      if (match.count(x) == 0 || dfs(e, match[x])) {
        match[x] = cur;
        return true;
      }
    }
  }
  return false;
}

int main() {
  int                   n;
  map<int, vector<int>> e;

  set<int> se;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    e[i].push_back(x);
    se.insert(x);
    se.insert(i);
    e[x].push_back(i);
  }

  int ans = 0;

  for (auto& x : se) {
    vis.clear();
    if (dfs(e, x)) ans++;
  }
  cout << ans / 2 << endl;
  return 0;
}