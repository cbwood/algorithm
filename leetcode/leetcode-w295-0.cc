/*
 *@File Name          :leetcode-w295-0.cc
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
  int rearrangeCharacters(string s, string target) {
    map<char, int> ma;
    map<char, int> mb;
    for (auto& c : s) ma[c]++;
    for (auto& c : target) mb[c]++;
    int ans = INT_MAX;
    for (auto& p : mb) { ans = min(ans, ma[p.first] / p.second); }
    return ans;
  }
};