/*
 *@File Name          :leetcode-w303-4.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/24 11:12
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int gao(int x) {
    int cnt = 0;
    while (x) {
      cnt += x & 1;
      x = x / 2;
    }
    return cnt;
  }
  long long countExcellentPairs(vector<int>& nums, int k) {
    vector<set<int>> a(100, set<int>{});
    for (auto x : nums) {
      int cnt = 0;
      int t   = x;
      while (x) {
        cnt += x & 1;
        x = x / 2;
      }
      a[cnt].insert(t);
    }
    long long cnt = 0;
    int       n   = 0;
    for (int i = 1; i < 100; i++) {
      if (i >= k) { cnt += a[i].size(); }
      n += a[i].size();
    }
    long long ans = cnt * n * 2 - cnt;
    for (int i = 1; i < k; i++) {
      for (int j = 1; j < k; j++) {
        for (auto& x : a[i]) {
          for (auto& y : a[j]) {
            if (gao(x & y) + gao(x | y) >= k) { ans++; }
          }
        }
      }
    }
    return ans;
  }
};