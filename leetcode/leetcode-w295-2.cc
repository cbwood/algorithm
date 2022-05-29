/*
*@File Name          :leetcode-w295-2.cc
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
  int totalSteps(vector<int>& nums) {
    int ans = 0;
    nums.push_back(INT_MAX);
    int n = nums.size();

    vector<int>  nxt(n), vec, vec2;
    vector<bool> vis(n + 1, true);

    for (int i = n - 1; i >= 0; --i) {
      nxt[i] = i + 1;
      if (i + 1 < n && nums[i] > nums[i + 1]) vec.push_back(i);
    }
    while (!vec.empty()) {
      vec2.clear();
      for (auto x : vec) {
        if (vis[x] && nums[x] > nums[nxt[x]]) {
          vis[nxt[x]] = false;
          nxt[x]      = nxt[nxt[x]];
          vec2.push_back(x);
        }
      }
      swap(vec, vec2);
      if (vec.empty()) break;
      ++ans;
    }
    return ans;
  }
};