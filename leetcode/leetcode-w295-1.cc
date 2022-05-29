/*
 *@File Name          :leetcode-w295-1.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/29 10:21
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  string discountPrices(string sentence, int discount) {
    string result;
    string ans;
    int    n    = sentence.size();
    int    prex = 0;
    for (int i = 0; i < n; i++) {
      if (sentence[i] != ' ' && i != n - 1) { continue; }
      if (i == n - 1) i = n;
      result       = sentence.substr(prex, i - prex);
      prex         = i + 1;
      string tmp   = result;
      bool   check = true;
      if (tmp[0] == '$') {
        double t    = 0;
        double tans = 0;
        int    len  = tmp.size();
        if (len == 1) { check = false; }
        for (int i = 1; i < len; i++) {
          if (tmp[i] >= '0' && tmp[i] <= '9') {
            t = t * 10 + tmp[i] - '0';
          } else {
            check = false;
            break;
          }
        }
        if (check) {
          tans = t;
          tans = tans * (1 - 1.0 * discount / 100);
          char ss[15];
          sprintf(ss, "%.2f", tans);
          string str(ss);
          tmp = "$" + str;
        }
      }
      if (ans.empty()) {
        ans = tmp;
      } else {
        ans.append(" ");
        ans.append(tmp);
      }
    }
    return ans;
  }
};