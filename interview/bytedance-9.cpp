/*
 *@File Name          :bytedance-9.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/21 20:16
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

bool solve(string s, string t) {
  int            ls = 0, rs = s.size() - 1;
  int            lt = 0, rt = t.size() - 1;
  vector<string> a;
  string         tmp;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '{') {
      if (!tmp.empty()) a.push_back(tmp);
      cout << tmp << endl;
    } else if (s[i] == '}') {
      tmp = "";
    } else {
      tmp.push_back(s[i]);
    }
  }
  if (!tmp.empty()) a.push_back(tmp);
  int k = 0;
  if (t.substr(lt, a[k].size()) != a[k]) return false;
  if (t.substr(t.size() - (*a.rbegin()).size(), (*a.rbegin()).size()) !=
      *a.rbegin())
    return false;
  k++;
  lt = a[0].size();
  while (k < a.size() && lt < t.size()) {
    tmp = t.substr(lt, a[k].size());
    if (tmp == a[k])
      lt += a[k++].size();
    else
      lt++;
  }
  return k >= a.size();
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  while (n--) {
    string t;
    cin >> t;
    if (solve(s, t)) {
      cout << "True" << endl;
    } else
      cout << "False" << endl;
  }
  return 0;
};