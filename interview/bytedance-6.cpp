/*
*@File Name          :bytedance-6.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/7/17 14:22
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

int main() {
  string s1, s2;
  cin >> s2 >> s1;
  int len1 = s1.size();
  int len2 = s2.size();
  int ans  = -1;
  for (int i = 0; i < len1; i++) {
    bool flag = true;
    for (int j = 0; j < len2 && i + j < len1; j++) {
      if (s1[i + j] != s2[j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}