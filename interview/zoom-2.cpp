/*
*@File Name          :zoom-2.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/10 19:31
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

bool vis[1000000];
int  ans;

void dfs(int cur, vector<vector<int>>& e) {
  for (auto& x : e[cur]) {
    if (!vis[x]) {
      vis[x] = true;
      ans++;
      dfs(x, e);
    }
  }
}

int main() {
  int n, q;
  cin >> q;

  int idx    = 0;
  int numstr = 0;

  map<string, int>       str2id;
  vector<vector<int>>    e;
  map<string, int>       namemap;
  vector<vector<string>> str;

  e.emplace_back();
  while (q--) {
    string name;
    int    opt;
    cin >> opt;
    if (opt == 1) {
      cin >> name >> n;
      vector<string> v;

      string tmp;
      cin >> tmp;
      v.emplace_back(tmp);
      n--;
      if (str2id[tmp] == 0) {
        str2id[tmp] = ++numstr;
        e.emplace_back();
      }
      string pre = tmp;
      while (n--) {
        cin >> tmp;
        v.emplace_back(tmp);
        if (str2id[tmp] == 0) {
          str2id[tmp] = ++numstr;
          e.emplace_back();
        }
        e[str2id[pre]].push_back(str2id[tmp]);
        e[str2id[tmp]].push_back(str2id[pre]);
        pre = tmp;
      }
      namemap[name] = idx++;
      str.emplace_back(v);
    } else {
      cin >> name;
      if (namemap.find(name) == namemap.end()) {
        cout << "error" << endl;
      } else {
        memset(vis, false, numstr + 1);
        ans = 0;
        for (auto& x : str[namemap[name]]) { vis[str2id[x]] = true; }
        for (auto& x : str[namemap[name]]) { dfs(str2id[x], e); }
        cout << ans << endl;
      }
    }
  }
  return 0;
}