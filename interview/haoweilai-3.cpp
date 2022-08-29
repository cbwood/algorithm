/*
*@File Name          :haoweilai-3.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/27 19:24
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

int main() {
  string s;
  cin >> s;
  s = s.substr(2);
  map<char, int> ma;

  int ans = 0;
  int l = 0, r = 0;
  int n = s.size();

  while (r < n) {
    ma[s[r]]++;
    while (ma[s[r]] > 1) {
      ma[s[l]]--;
      l++;
    }
    r++;

    ans = max(ans, r - l);
  }
  cout << ans << endl;
  return 0;
}