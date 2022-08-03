/*
 *@File Name          :leetcode-w304-4.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/31 10:32
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  vector<int>  cnt, v;
  vector<bool> vis;
  int          res, n;

  int longestCycle(vector<int>& edges) {
    n = edges.size();
    v.resize(n);
    for (int i = 0; i < n; i++) v[i] = edges[i];
    cnt.resize(n, 0);
    vis.resize(n, false);

    for (int i = 0; i < n; i++)
      if (edges[i] != -1) {
        cnt[edges[i]]++;  //入度++
      }
    TopSort();  //把不是环的check
    res = -1;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) { DFS(i, 0); }
    }
    if (res == 0) res = -1;
    return res;
  }

  queue<int> Q;

  void TopSort() {
    while (!Q.empty()) { Q.pop(); }
    for (int i = 0; i < n; i++) {
      if (cnt[i] == 0) { Q.push(i); }
    }
    int now;
    while (!Q.empty()) {
      now = Q.front();
      Q.pop();
      vis[now] = true;
      if (v[now] != -1) {
        cnt[v[now]]--;
        if (v[now] != -1 && cnt[v[now]] == 0) { Q.push(v[now]); }
      }
    }
  }

  void DFS(int idx, int cnt) {
    if (idx == -1) return;
    if (!vis[idx]) {
      vis[idx] = true;
      DFS(v[idx], cnt + 1);
    } else {
      res = max(res, cnt);
    }
  }
};