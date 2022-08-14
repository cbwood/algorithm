/*
 *@File Name          :zoom-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/10 19:19
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e5 + 10;
bool      vis[maxn];

long long      ans = 0;
map<char, int> ma;

void dfs(vector<vector<int>>& e, int cur, int sumx, string& s) {
  if (vis[cur]) return;
  vis[cur] = true;
  ans += abs(sumx);
  for (auto& x : e[cur]) { dfs(e, x, sumx + ma[s[x - 1]], s); }
}

int main() {
  int    n;
  string s;
  cin >> n >> s;
  ma['R'] = 1;
  ma['B'] = -1;
  vector<vector<int>> e(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(e, 1, ma[s[0]], s);
  cout << ans << endl;
  return 0;
}