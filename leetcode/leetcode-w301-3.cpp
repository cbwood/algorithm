/*
 *@File Name          :leetcode-w301-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/10 11:21
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  bool canChange(string start, string target) {
    vector<int> sl;
    vector<int> sr;
    vector<int> tl;
    vector<int> tr;

    vector<int> sumsl;
    vector<int> sumtl;
    vector<int> sumsr;
    vector<int> sumtr;

    for (int i = 0; i < start.size(); i++) {
      if (start[i] == 'L') sl.push_back(i), sumsl.push_back(sr.size());
      if (start[i] == 'R') sr.push_back(i), sumsr.push_back(sl.size());
    }

    for (int i = 0; i < target.size(); i++) {
      if (target[i] == 'L') tl.push_back(i), sumtl.push_back(tr.size());
      if (target[i] == 'R') tr.push_back(i), sumtr.push_back(tl.size());
    }

    if (sl.size() != tl.size() || sr.size() != tr.size()) return false;

    for (int i = 0; i < sl.size(); i++) {
      if (!(sl[i] >= tl[i] && sumsl[i] == sumtl[i])) return false;
    }

    for (int i = 0; i < sr.size(); i++) {
      if (!(sr[i] <= tr[i] && sumsr[i] == sumtr[i])) return false;
    }
    return true;
  }
};