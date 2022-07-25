/*
 *@File Name          :leetcode-w303-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/24 10:17
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  char repeatedCharacter(string s) {
    map<char, int> ma;
    for (auto& x : s) {
      ma[x]++;
      if (ma[x] == 2) return x;
    }
    return 'a';
  }
};