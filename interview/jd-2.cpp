/*
 *@File Name          :jd-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/27 19:57
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"
using namespace std;

int main() {
  int    n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  for (int i = 0; i < k; i++) { s[i] = toupper(s[i]); }
  for (int i = k; i < n; i++) { s[i] = tolower(s[i]); }
  cout << s << endl;
  return 0;
}