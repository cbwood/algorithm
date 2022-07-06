/*
 *@File Name          :offer2-119.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/6 15:43
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "map"
#include "set"
#include "vector"
using namespace std;

class Solution {
 public:
  map<int, int> f;
  map<int, int> rank;

  int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      f[x] = y;
      rank[y] += rank[x];
    }
  }

  int longestConsecutive(vector<int>& nums) {
    set<int> all;

    for (auto& x : nums) {
      all.insert(x);
      f[x]    = x;
      rank[x] = 1;
    }
    for (auto& x : nums) {
      if (all.count(x - 1)) { merge(x, x - 1); }
      if (all.count(x + 1)) merge(x, x + 1);
    }
    int ans = 0;
    for (auto& x : rank) ans = max(ans, x.second);
    return ans;
  }
};