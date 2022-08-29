/*
 *@File Name          :haoweilai-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/27 19:06
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

vector<vector<string>> ans;

bool check(string& t) {
  int l = 0, r = t.size() - 1;
  while (l < r) {
    if (t[l] != t[r]) return false;
    l++;
    r--;
  }
  return true;
}

void dfs(string& s, string& t, int cur, vector<string>& q) {
  if (cur >= s.size()) {
    if (check(t)) {
      if (!t.empty()) {
        q.push_back(t);
        ans.push_back(q);
        q.pop_back();
      }
    }
    return;
  }

  if (!t.empty() && check(t)) {
    q.push_back(t);
    string tt = string(1, s[cur]);
    dfs(s, tt, cur + 1, q);
    q.pop_back();
  }
  t.push_back(s[cur]);
  dfs(s, t, cur + 1, q);
  t.pop_back();
}

int main() {
  string s;
  cin >> s;
  s = s.substr(2);
  string         t;
  vector<string> q;
  dfs(s, t, 0, q);
  string a;
  a.push_back('[');

  for (auto& x : ans) {
    a.push_back('[');
    for (auto& y : x) {
      a.push_back('"');
      a += y;
      a.push_back('"');
      a.push_back(',');
    }
    a.pop_back();
    a.push_back(']');
    a.push_back(',');
  }
  a.push_back(']');
  cout << a << endl;
  return 0;
}