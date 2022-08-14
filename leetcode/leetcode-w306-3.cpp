/*
 *@File Name          :leetcode-w306-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/14 11:07
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  string           ans;
  bool             vis[10];
  map<int, string> ma;

  void dfs(string pattern, string t, int idx, int pre) {
    if (idx == pattern.size()) {
      if (ans.empty() || ans > t) { ans = t; }
      return;
    }
    if (pattern[idx] == 'I') {
      for (int i = pre + 1; i <= 9; i++) {
        if (!vis[i]) {
          vis[i] = true;
          dfs(pattern, t + ma[i], idx + 1, i);
          vis[i] = false;
        }
      }
    } else {
      for (int i = pre - 1; i >= 1; i--) {
        if (!vis[i]) {
          vis[i] = true;
          dfs(pattern, t + ma[i], idx + 1, i);
          vis[i] = false;
        }
      }
    }
  }

  string smallestNumber(string pattern) {
    memset(vis, false, sizeof vis);
    for (int i = 0; i <= 9; i++) { ma[i] = to_string(i); }
    for (int i = 1; i < 10; i++) {
      vis[i] = true;
      dfs(pattern, ma[i], 0, i);
      vis[i] = false;
    }
    return ans;
  }
};