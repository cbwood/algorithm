/*
 *@File Name          :leetcode-w302-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/17 10:36
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  vector<int> smallestTrimmedNumbers(vector<string>&      nums,
                                     vector<vector<int>>& queries) {
    vector<int> ans;

    int n = nums.size();
    int m = nums[0].size();

    for (auto& x : queries) {
      vector<pair<string, int>> v;

      for (int i = 0; i < n; i++) {
        v.push_back({nums[i].substr(m - x[1]), i});
      }

      std::sort(v.begin(), v.end());
      ans.push_back(v[x[0] - 1].second);
    }
    return ans;
  }
};