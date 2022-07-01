/*
*@File Name          :offer2-086.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/7/1 9:40
*@Description        :
*@Function List      :
*@History            :
*/

#include "algorithm"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<vector<string>> ans;
  vector<vector<int>>    vis;

  bool check(const string& s, int l, int r) {
    int ll = l, rr = r;
    if (vis[l][r] != -1) return vis[l][r];
    while (l <= r) {
      if (s[l] != s[r]) return vis[ll][rr] = false;
      l++;
      r--;
    }
    return vis[ll][rr] = true;
  }

  void dfs(const string& s, int l, int r, vector<string>& t) {
    if (l == s.size()) {
      ans.push_back(t);
      return;
    }
    for (int i = l; i < s.size(); i++) {
      if (check(s, l, i)) {
        t.push_back(s.substr(l, i - l + 1));
        dfs(s, i + 1, i + 1, t);
        t.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    vector<string> t;
    vis.resize(16, vector<int>(16, -1));
    dfs(s, 0, 0, t);
    return ans;
  }
};