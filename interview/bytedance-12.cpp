/*
*@File Name          :bytedance-12.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/28 10:49
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

vector<int> gao(string& s) {
  int         tmp = 0;
  vector<int> t;
  for (auto& x : s) {
    if (x == ' ') {
      t.push_back(tmp);
      tmp = 0;
    } else
      tmp = tmp * 10 + x - '0';
  }
  t.push_back(tmp);
  return t;
}

vector<int> re() {
  vector<int> t;
  char        ch;
  while ((ch = getchar()) != '\n') {
    if (ch != ' ') t.push_back(ch - '0');
    cout << ch;
  }
  return t;
}

vector<vector<int>> e(10);
vector<bool>        vis;

int dfs(int cur) {
  for (auto& x : e[cur]) {
    if (!vis[x]) {
      vis[x] = true;
      if (dfs(x) == 0) return 0;
    } else
      return 0;
  }
  return 1;
}

int main() {
  int n;
  scanf("%d", &n);
  getchar();

  string s;

  vector<int> t = re();
  n--;
  while (n--) {
    //    cin >> s;
    //   getline(cin, s);
    vector<int> tmp = re();
    cout << tmp.size() << " " << endl;
    for (int i = 1; i < tmp.size(); i++) { e[tmp[0]].push_back(tmp[i]); }
  }
  int m = t.size();
  for (int i = 0; i < m - 1; i++) {
    vis.resize(12, false);
    vis[t[i]] = true;
    cout << dfs(t[i]) << " ";
  }
  cout << dfs(t[m - 1]) << endl;
  return 0;
}